#include "layer_driver/circuit/emergency.hpp"

Emergency::Emergency(Digital &emergencyPin, Digital &readPin){
	this->emergencyPin = &emergencyPin;
	this->readPin = &readPin;
	state=true;
	emergencyState=0;
}

int Emergency::setup(){
	int i=0;
	i+=emergencyPin->setupDigitalOut();
	i+=readPin->setupDigitalInPullUp();
	return i;
}

void Emergency::cycle(){
	if(state == true){
		emergencyPin->digitalHigh();
	}else {
		emergencyPin->digitalLow();
	}
	emergencyState = readPin->digitalRead();
}

int Emergency::readOutside(){
	return emergencyState;
}

int Emergency::readInside(){
	if(state == false){	//mainで掛けている
		return 0;
	}else return 1;	//かけていない
}

void Emergency::on(){	//緊急停止
	state = false;
}

void Emergency::off(){	//緊急停止解除
	state = true;
}
