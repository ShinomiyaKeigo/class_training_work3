//2015/11/21 Nagatani Tomoki
#ifndef DC_MOTOR_CONTROLLER_HPP
#define DC_MOTOR_CONTROLLER_HPP

#include <stdint.h>
#include "encoder.hpp"
#include "../layer_controller/advanced_encoder.hpp"
#include "../layer_controller/motor_controller.hpp"
#include "layer_driver/circuit/motor_driver.hpp"
#include "../layer_application/console.hpp"
#include "string.h"
#include "stdlib.h"
class Integrator1{
public:
	Integrator1();
	void cycle();
	typedef struct{
		float pos;
		float vel;
		float acc;
	}Physic1dof_t;

	int dt(float dt);
	float time(){return timeCounter;};

	void pos(float value){target.pos=value;mode=MODE_POS;};
	void vel(float value){target.vel=value;mode=MODE_VEL;};

	float pos(){return relative.pos;};
	float vel(){return relative.vel;};
	float acc(){return relative.acc;};

	void setLimitVel(float value){limit.vel=value;};
	void setLimitAcc(float value){limit.acc=value;};
	void setStdAcc(float value){target.acc=value;};

	Physic1dof_t target;
	Physic1dof_t limit;
	Physic1dof_t relative;

	float dtData;
	float timeCounter;
	void Physic1dofInit(Physic1dof_t &value);

	float todebug0, todebug1;

	int mode;
	enum{
		MODE_NULL,
		MODE_VEL,
		MODE_POS
	};
};

class DCMotorController:public MotorController,public ConsoleCommand{
public:
	DCMotorController(MotorDriver &md,AdvancedEncoder &enc,float controlInterval,char command[11]=0);
	void duty(float duty){targetDuty=duty;executionTask=DCMC_DUTY;};
	float duty(){return motor->duty();};
	void outRev(bool value){motor->outRev(value);};
	void outRev(){motor->outRev();};
	void encRev(bool value){enc->rev(value);};
	void encRev(){enc->rev();};
	void setGearRatio(float value){gearRatio=value;};//reduction gear ratio
	float getGearRatio(){return gearRatio;};

	int setup();
	void cycle();
	char *iam(){return command;};
	void stop(){executionTask=DCMC_NULL;};

	void pos(float pos){integ.pos(pos*gearRatio);executionTask=DCMC_POS;};
	void vel(float vel){integ.vel(vel*gearRatio);executionTask=DCMC_VEL;};
	float idealPos(){return integ.pos()/gearRatio;};
	float idealVel(){return integ.vel()/gearRatio;};

	void setPosGain(float value){posGain=value;};
	void setVelGain(float value){velGain=value;};
	void setAccGain(float value){accGain=value;};
	float getPosGain(){return posGain;};
	float getVelGain(){return velGain;};
	float getAccGain(){return accGain;};

	void setWeakPosGain(float value){posGainWeak=value;};
	void setWeakVelGain(float value){velGainWeak=value;};
	void setWeakAccGain(float value){accGainWeak=value;};
	float getWeakPosGain(){return posGainWeak;};
	float getWeakVelGain(){return velGainWeak;};
	float getWeakAccGain(){return accGainWeak;};
	void setWeakGainArea(float radian){weakGainArea=radian*gearRatio;};
	float getWeakGainArea(){return weakGainArea;};

	void setWeakGainDirec(float value){weakGainDirec = value;};
	void setWeakDirecPosGain(float value){posGainWeakDirec = value;};
	void setWeakDirecVelGain(float value){velGainWeakDirec = value;};
	void setWeakDirecAccGain(float value){accGainWeakDirec = value;};


	void setLimitVel(float value){integ.setLimitVel(value*gearRatio);};
	void setLimitAcc(float value){integ.setLimitAcc(value*gearRatio);};
	void setStdAcc(float value){integ.setStdAcc(value*gearRatio);};
	void setLimitCurrent(float value){limitCurrent=value;};

	void setLimitPosDiff(float value){limitPosDiff=value;};
	void setLimitVelDiff(float value){limitVelDiff=value;};

	void setDutyAreaCw(float cw);
	void setDutyAreaCcw(float ccw);
	void setPosAreaCw(float cw);
	void setPosAreaCcw(float ccw);

	int count(){return enc->count();};
	float revolution(){return enc->revolution()/gearRatio;};
	float radian(){return enc->radian()/gearRatio;};
	float rps(){return enc->rps()/gearRatio;};
	float rads(){return enc->rads()/gearRatio;};

	void setSourceVoltage(float value);//[V]

	void setSpeedConstant(float value);//[V/rads]
	void setForwardSpeedConstant(float value);
	void setBackSpeedConstant(float value);

	void setTorqueConstantData(float value){};//[rads]
	void setTerminalResistance(float value);//[Ω]

	void current(float value);

	int commandCompare(char *command){
		return !(strcmp(this->command,command));
	};
	int commandRequest(int argc,char **argv){
		if(!strcmp(argv[1], "help")){
			consolePrintf((char*)"\"%s\" COMMAND LIST\r\n",command);
			consolePrintf((char*)"[pgain]:set/view\r\n");
			consolePrintf((char*)"[vgain]:set/view\r\n");
			consolePrintf((char*)"[again]:set/view\r\n");
			consolePrintf((char*)"[duty]:set/view\r\n");
			consolePrintf((char*)"[pos]:set/view\r\n");
			consolePrintf((char*)"[vel]:set/view\r\n");
		}else if(!strcmp(argv[1],"pgain")){
			if(argc == 2)consolePrintf((char*)"%s pgain->%f\r\n",command,getPosGain());
			else if(argc == 3){
				setPosGain(atoff(argv[2]));
				consolePrintf((char*)"%s pgain->%f\r\n",command,getPosGain());
			}else consolePrintf((char*)"command error\r\n");
		}else if(!strcmp(argv[1],"vgain")){
			if(argc == 2)consolePrintf((char*)"%s vgain->%f\r\n",command,getVelGain());
			else if(argc == 3){
				setVelGain(atoff(argv[2]));
				consolePrintf((char*)"%s vgain->%f\r\n",command,getVelGain());
			}else consolePrintf((char*)"command error\r\n");
		}else if(!strcmp(argv[1],"again")){
			if(argc == 2)consolePrintf((char*)"%s again->%f\r\n",command,getAccGain());
			else if(argc == 3){
				setAccGain(atoff(argv[2]));
				consolePrintf((char*)"%s again->%f\r\n",command,getAccGain());
			}else consolePrintf((char*)"command error\r\n");
		}else if(!strcmp(argv[1],"duty")){
			if(argc == 2)consolePrintf((char*)"%s duty->%f\r\n",command,duty());
			else if(argc == 3){
				duty(atoff(argv[2]));
				consolePrintf((char*)"%s duty->%f\r\n",command,duty());
			}else consolePrintf((char*)"command error\r\n");
		}else if(!strcmp(argv[1], "count")){
			if(argc == 2)consolePrintf((char*)"%s count->%d\r\n",command, count());
			else consolePrintf((char*)"command error\r\n");
		}else if(!strcmp(argv[1],"pos")){
			if(argc == 2)consolePrintf((char*)"%s pos->%f\r\n",command, radian());
			else if(argc == 3){
				pos(atoff(argv[2]));
				consolePrintf((char*)"%s pos->%f\r\n",command,atoff(argv[2]));
			}else consolePrintf((char*)"command error\r\n");
		}else if(!strcmp(argv[1],"vel")){
			if(argc == 2)consolePrintf((char*)"%s vel->%f\r\n",command, rads());
			else if(argc == 3){
				vel(atoff(argv[2]));
				consolePrintf((char*)"%s vel->%f\r\n",command,atoff(argv[2]));
			}else consolePrintf((char*)"command error\r\n");
		}else{
			if(argc >= 2)consolePrintf((char*)"There is no \"%s\" in the command of \"%s\"\r\n", argv[1], command);
			else consolePrintf((char*)"Please enter the command of \"%s\"\r\n", command);
		}
		return 0;
	};

	MotorDriver *motor;
	AdvancedEncoder *enc;
	//private:
	enum{
		DCMC_NULL=0,
		DCMC_DUTY,
		DCMC_POS,
		DCMC_VEL,
		DCMC_CURRENT
	};
	char command[11];
	int executionTask;
	int time;


	float targetDuty;
	float targetCurrent;
	Integrator1 integ;

	float posGain;
	float velGain;
	float accGain;

	float posGainWeak;
	float velGainWeak;
	float accGainWeak;
	float weakGainArea;

	float weakGainDirec;
	float posGainWeakDirec;
	float velGainWeakDirec;
	float accGainWeakDirec;

	float driveDutyMax;//mainly plus
	float driveDutyMin;//mainly minus
	float posMax;
	float posMin;

	float limitPosDiff;
	float limitVelDiff;

	float gearRatio;

	float sourceVoltageData;//[V]
	float speedConstantData;//[V/rads]
	float forwardSpeedConstantData;
	float backSpeedConstantData;
	float torqueConstantData;
	float terminalResistance;

	float limitCurrent;

	float currentToDuty(float value);
	float dutyToCurrent(float value);
};

#endif//DC_MOTOR_CONTROLLER_HPP
