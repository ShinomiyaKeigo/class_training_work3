#include "dc_motor_controller.hpp"
#include "mcutime.h"
#include <math.h>
#include "util.hpp"

Integrator1::Integrator1(){
	Physic1dofInit(target);
	Physic1dofInit(limit);
	Physic1dofInit(relative);
	timeCounter=0;
}

int Integrator1::dt(float dt){
	if(dt<0)return 1;
	this->dtData=dt;
	return 0;
}

void Integrator1::Physic1dofInit(Physic1dof_t &value){
	value.pos=0.0;
	value.vel=0.0;
	value.acc=0.0;
}

void Integrator1::cycle(){
	//目標位置を元に減速に向けた目標速度を指定
	//目標との距離
	if(mode==MODE_POS){
		float xDiff=target.pos-relative.pos;
		float noHalfdown=fsign(xDiff)*sqrtf(2*target.acc*fabsf(xDiff));
		target.vel=fsign(xDiff)*(sqrtf(2*target.acc*fabsf(xDiff))-dtData*target.acc/2);

		float lastVelocity=xDiff/dtData;
		//残り１制御周期で目標位置に到達する場合は目標にぴったり合う速度を算出して行う
		//ぴったり合わせようと速度を加減し続けて速度が振動することを防いでいる。
		target.vel=abs_min(lastVelocity,target.vel);

		if(target.vel*fsign(xDiff)<0.0f){
			target.vel=abs_min(lastVelocity,noHalfdown);
		}

		//減速に向けた目標速度を制限速度に収める
		//target.vel=constrain(target.vel,-limit.vel,limit.vel);
		target.vel = floatlimit(-limit.vel, target.vel, limit.vel);
	}else if(mode==MODE_VEL){

	}else{
		target.vel=0.0f;
	}

	//加速度測定用
	float oldVelocityX;
	oldVelocityX = relative.vel;

	//新たな速度を算出。目標速度を制限減速度と目標加速度の中で実現
	//加速に向けた目標速度を算出
	//目標加速度内で実現可能な新たな速度の上限と加減を計算
	float xVelocityUnderLimit,xVelocityOverLimit;
	if(target.vel - relative.vel > 0.0f){
	//if(relative.vel){
		xVelocityUnderLimit = relative.vel - limit.acc * dtData;
		xVelocityOverLimit = relative.vel + target.acc * dtData;
	}else{
		xVelocityUnderLimit = relative.vel - target.acc * dtData;
		xVelocityOverLimit = relative.vel + limit.acc * dtData;
	}
	todebug0 = xVelocityOverLimit;
	todebug1 = xVelocityUnderLimit;
	//float targetVelocityX=constrain(target.vel,xVelocityUnderLimit,xVelocityOverLimit);
	float targetVelocityX = floatlimit(xVelocityUnderLimit, target.vel, xVelocityOverLimit);
	//速度制限をかける
	//targetVelocityX = constrain(targetVelocityX,-limit.vel,limit.vel);
	targetVelocityX = floatlimit(-limit.vel, targetVelocityX, limit.vel);
	//targetVelocityX = floatlimit(-3.14, targetVelocityX, 3.14);
	//代入
	relative.vel = targetVelocityX;

	//速度変化から加速度を求めて代入
	relative.acc=(relative.vel - oldVelocityX) / dtData;

	//一応相対速度のほうも積分
	//relative.position=relative.position+relative.velocity*dtData;
	relative.pos += relative.vel * dtData;

	//時間を進める
	timeCounter += dtData;

}


DCMotorController::DCMotorController(MotorDriver &md,AdvancedEncoder &enc,float controlInterval,char command[11]){
	this->motor=&md;
	this->enc=&enc;
	//consolePrintf();
	strcpy(this->command,command);

	posGain=0.0;
	velGain=0.0;
	accGain=0.0;

	posGainWeak=0.0;
	velGainWeak=0.0;
	accGainWeak=0.0;
	weakGainArea=0.0;

	weakGainDirec = 0.0;
	posGainWeakDirec = 0.f;
	velGainWeakDirec = 0.f;
	accGainWeakDirec = 0.f;

	targetDuty=0;

	driveDutyMin=-1.0;
	driveDutyMax=1.0;

	posMax=0.0;
	posMin=0.0;

	executionTask=0;
	time=0;

	sourceVoltageData=10000;
	speedConstantData=0;
	forwardSpeedConstantData=0.0f;
	backSpeedConstantData=0.0f;
	torqueConstantData=0.0;
	terminalResistance=0.0;

	limitCurrent=0.0;

	limitPosDiff=0.0;//0.0で制限なし
	limitVelDiff=0.0;//0.0で制限なし

	gearRatio=1.0;

	integ.dt(controlInterval);
}

int DCMotorController::setup(){
	int i=0;
	i+=(0!=motor->setup());
	i+=(0!=enc->setup());
	return i;
}

extern int cytime;
#include <stdio.h>
#include "pin.hpp"
void DCMotorController::cycle(){
	float outputValue=0.0f;
	time=micros();
	enc->cycle();
	//printf("%d,",(int)(micros()-cytime));
	if(executionTask==DCMC_NULL){
		outputValue=0.0f;
		motor->duty(outputValue);
		motor->cycle();
		integ.relative.pos=enc->radian();
		integ.relative.vel=0.0f;
		//printf("%d\n",(int)(micros()-cytime));
		return;
	}else if(executionTask==DCMC_DUTY){
		integ.relative.pos=enc->radian();
		integ.relative.vel=0.0f;
		outputValue=targetDuty;
	}else if(executionTask==DCMC_POS||executionTask==DCMC_VEL){
		/*test*/
		integ.cycle();
		if(posMin!=posMax)integ.relative.pos=constrain(integ.pos(),posMin,posMax);

		//ゲインを駆動方向によって変化させる
		if(weakGainDirec != 0){
			if(fabs(enc->radian()-integ.pos())<weakGainArea){
				outputValue=-(enc->radian()-integ.pos()) * posGainWeak;
				outputValue-=(enc->rads()-integ.vel()) * velGainWeak;
				outputValue-=(enc->rads2()-integ.acc()) * accGainWeak;
			}else{
				if(((weakGainDirec < 0) && (integ.pos() - enc->radian()) < 0) || ((weakGainDirec > 0) && (integ.pos() - enc->radian()) > 0)){

					outputValue=-(enc->radian()-integ.pos())*posGainWeakDirec;
					outputValue-=(enc->rads()-integ.vel())*velGainWeakDirec;
					outputValue-=(enc->rads2()-integ.acc())*accGainWeakDirec;
				}else{
					outputValue=-(enc->radian()-integ.pos())*posGain;
					outputValue-=(enc->rads()-integ.vel())*velGain;
					outputValue-=(enc->rads2()-integ.acc())*accGain;
				}
			}
		} else {
			if(fabs(enc->radian()-integ.pos())<weakGainArea){
				outputValue=-(enc->radian()-integ.pos())*posGainWeak;
				outputValue-=(enc->rads()-integ.vel())*velGainWeak;
				outputValue-=(enc->rads2()-integ.acc())*accGainWeak;
			}else{
				outputValue=-(enc->radian()-integ.pos())*posGain;
				outputValue-=(enc->rads()-integ.vel())*velGain;
				outputValue-=(enc->rads2()-integ.acc())*accGain;
			}
		}

		//if(fabsf(enc->radian() - integ.pos()) < dtor(0.5f))outputValue = 0.f;



/*
		integ.cycle();
		if(limitPosDiff!=0.0f){
			if(integ.pos()-enc->radian()>limitPosDiff)integ.relative.pos=enc->radian()+limitPosDiff;
			if(enc->radian()-integ.pos()>limitPosDiff)integ.relative.pos=enc->radian()-limitPosDiff;
		}
		if(limitVelDiff!=0.0f){
			if(integ.vel()-enc->rads()>limitVelDiff)integ.relative.vel=enc->rads()+limitVelDiff;
			if(enc->rads()-integ.vel()>limitVelDiff)integ.relative.vel=enc->rads()-limitVelDiff;
		}

		if(posMin!=posMax)integ.relative.pos=constrain(integ.pos(),posMin,posMax);

		//ゲインを駆動方向によって変化させる
		if(weakGainDirec != 0){
			if(fabs(enc->radian()-integ.pos())<weakGainArea){
				outputValue=-(enc->radian()-integ.pos()) * posGainWeak;
				outputValue-=(enc->rads()-integ.vel()) * velGainWeak;
				outputValue-=(enc->rads2()-integ.acc()) * accGainWeak;
			}else{
				//if((weakGainDirec > 0 && (integ.pos() - enc->radian()) > 0) || (weakGainDirec < 0 && (integ.pos() - enc->radian()) < 0)){
				if(((weakGainDirec < 0) && (integ.pos() - enc->radian()) < 0) || ((weakGainDirec > 0) && (integ.pos() - enc->radian()) > 0)){

					outputValue=-(enc->radian()-integ.pos())*posGainWeakDirec;
					outputValue-=(enc->rads()-integ.vel())*velGainWeakDirec;
					outputValue-=(enc->rads2()-integ.acc())*accGainWeakDirec;
				}else{
					outputValue=-(enc->radian()-integ.pos())*posGain;
					outputValue-=(enc->rads()-integ.vel())*velGain;
					outputValue-=(enc->rads2()-integ.acc())*accGain;
				}
			}
		} else {
			if(fabs(enc->radian()-integ.pos())<weakGainArea){
				outputValue=-(enc->radian()-integ.pos())*posGainWeak;
				outputValue-=(enc->rads()-integ.vel())*velGainWeak;
				outputValue-=(enc->rads2()-integ.acc())*accGainWeak;
			}else{
				outputValue=-(enc->radian()-integ.pos())*posGain;
				outputValue-=(enc->rads()-integ.vel())*velGain;
				outputValue-=(enc->rads2()-integ.acc())*accGain;
			}
		}
		todebug0 = integ.pos();

		if(integ.pos()-enc->radian()>0.0f&&forwardSpeedConstantData!=0.0f){
			outputValue+=(integ.vel())*forwardSpeedConstantData/sourceVoltageData;
		}else if(integ.pos()-enc->radian()<0.0f&&backSpeedConstantData!=0.0f){
			outputValue+=(integ.vel())*backSpeedConstantData/sourceVoltageData;
		}else{
			outputValue+=(integ.vel())*speedConstantData/sourceVoltageData;
		}
		outputValue+=integ.acc()*torqueConstantData/sourceVoltageData;
		*/
	}else if(executionTask==DCMC_CURRENT){
		outputValue=currentToDuty(targetCurrent);
	}
	if(limitCurrent!=0.0){
		float limitValue=fabsf(max(fabsf(currentToDuty(-limitCurrent)),fabsf(currentToDuty(limitCurrent))));
		outputValue=constrain(outputValue,-limitValue,limitValue);
		//printf("%f\n",limitValue);
	}
	//Serial2 ss;ss.printf("%d  %f  %f\r\n",executionTask,integ.target.vel,outputValue);
	motor->duty(constrain(outputValue,driveDutyMin,driveDutyMax));
	motor->cycle();
	//printf("%d\n",(int)(micros()-cytime));
}

void DCMotorController::setDutyAreaCw(float cw){
	driveDutyMax=cw;
}

void DCMotorController::setDutyAreaCcw(float ccw){
	driveDutyMin=ccw;
}

void DCMotorController::setPosAreaCw(float cw){
	posMax=cw;
}

void DCMotorController::setPosAreaCcw(float ccw){
	posMin=ccw;
}

void DCMotorController::setSourceVoltage(float value){
	if(value<=0.0f)return;
	sourceVoltageData=value;
}

void DCMotorController::setSpeedConstant(float value){
	speedConstantData=value;
}
void DCMotorController::setForwardSpeedConstant(float value){
	forwardSpeedConstantData=value;
}
void DCMotorController::setBackSpeedConstant(float value){
	backSpeedConstantData=value;
}

void DCMotorController::setTerminalResistance(float value){
	terminalResistance=value;
}
float DCMotorController::currentToDuty(float value){
	return terminalResistance*value/sourceVoltageData+enc->rads()*gearRatio*speedConstantData/sourceVoltageData;
}
float DCMotorController::dutyToCurrent(float value){
	if(terminalResistance==0.0)return 0;
	return (value-enc->rads()*speedConstantData/sourceVoltageData)/terminalResistance;
}

void DCMotorController::current(float value){
	executionTask=DCMC_CURRENT;
	targetCurrent=value;
}
