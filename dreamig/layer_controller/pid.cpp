#include "layer_controller/pid.hpp"

Pid::Pid(){
	kp = 0.f;
	ki = 0.f;
	kd = 0.f;
	div = 0.f;
	kpSum = 0.f;
	kiSum = 0.f;
	kdSum = 0.f;
	oldDeviation = 0.f;
	old2Deviation = 0.f;
}

void Pid::setGain(float kp, float ki, float kd, float div){
	this->kp = kp;
	this->ki = ki;
	this->kd = kd;
	this->div = div;
	reset();
}

void Pid::reset(){
	kpSum = 0.f;
	kiSum = 0.f;
	kdSum = 0.f;
	oldDeviation = 0.f;
	old2Deviation = 0.f;
}

float Pid::control(float target, float operation){
	float deviation = target - operation;
	kpSum += kp*(deviation - oldDeviation)/div;
	kiSum += ki*deviation/div;
	kdSum += kd*((deviation-oldDeviation) - (oldDeviation-old2Deviation))/div;
	old2Deviation = oldDeviation;
	oldDeviation = deviation;
	return kpSum +  kiSum + kdSum;
}
