#include "dc_motor_driver.hpp"

DCMotorDriver::DCMotorDriver(Pwm *pwm0,Pwm *pwm1){
    this->pwm0 = pwm0;
    this->pwm1 = pwm1;
    order=1;
}

int DCMotorDriver::setup(){
    int r;
    r=pwm0->setupPwmOut(100,0.0);
    r+=pwm1->setupPwmOut(100,0.0);
    return r;
}

void DCMotorDriver::duty(float duty){
    duty=order*floatlimit(-LIMIT,duty,LIMIT);

    duty0=duty/2.0+LIMIT/2.0;
    duty1=-duty/2.0+LIMIT/2.0;

    pwm0->pwmWrite(duty0);
    pwm1->pwmWrite(duty1);
}

void DCMotorDriver::outRev(bool flag){
    if(flag==1){
        order = -1;
    }else{
    	order = 1;
    }
}

void DCMotorDriver::outRev(){

}

void DCMotorDriver::free(){

}
float DCMotorDriver::duty(){
	return 0;
}
void DCMotorDriver::cycle(){

}
