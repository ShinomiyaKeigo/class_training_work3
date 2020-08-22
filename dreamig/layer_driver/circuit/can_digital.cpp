#include "layer_driver/circuit/can_digital.hpp"
#include "layer_driver/base/util.hpp"


CanDigital::CanDigital(Can &can,int number){
	can.addHandler(this);
	runSetupOnce=false;

	this->taskId = CAN_DIGITAL_ID + number*2;
	this->setupId = taskId | 0x080;
	this->slaveTaskId = CAN_DIGITAL_ID + (number*2+1);
	this->slaveSetupId = slaveTaskId | 0x080;

	pin0.assignPinNumber(0,this);
	pin1.assignPinNumber(1,this);
	pin2.assignPinNumber(2,this);
	pin3.assignPinNumber(3,this);
	pin4.assignPinNumber(4,this);
	pin5.assignPinNumber(5,this);
	pin6.assignPinNumber(6,this);
	pin7.assignPinNumber(7,this);


	pins[0] = &pin0;
	pins[1] = &pin1;
	pins[2] = &pin2;
	pins[3] = &pin3;
	pins[4] = &pin4;
	pins[5] = &pin5;
	pins[6] = &pin6;
	pins[7] = &pin7;

	readData=0x00;
	setupFlag = false;
}

int CanDigital::setup(){
	if(runSetupOnce==false){
		if(!canSetup()){
			runSetupOnce=true;
			canSetId(taskId);
			canSetId(setupId);
			return 0;
		}else
			return 1;
	}
	return 0;
}

int CanDigital::canId(int id){
	if( id == setupId)setupFlag=true;
	else setupFlag=false;
	return ( id & 0xf7f) == this->taskId;
}

int CanDigital::canRead(int id,int number,unsigned char data[8]){
	if(setupFlag){
		for(int pin=0; pin<8; pin++){
			if( (data[0] >> pin) == 0x01 ){
				pins[pin]->Task = data[1];
				break;
			}
		}
		setupFlag=false;
	}
	else this->readData=data[0];
}

void CanDigital::cycle(){
	unsigned char data[8]={0};
	//DigitalRead
	for(int pin=0; pin<8; pin++){
		if(   pins[pin]->Setup == pins[pin]->CAN_DIGITAL_SETUP_IN
				||pins[pin]->Setup == pins[pin]->CAN_DIGITAL_SETUP_PULLUP
				||pins[pin]->Setup == pins[pin]->CAN_DIGITAL_SETUP_PULLDOWN){

			if( (0x01 << pin) & this->readData)pins[pin]->pinState=1;
			else pins[pin]->pinState=0;
		}
	}

	//DigitalWrite
	int tasknull=0;
	for(int pin=0; pin<8; pin++){
		switch(pins[pin]->Task){
		case pins[pin]->CAN_DIGITAL_TASK_READ:
		data[0] |= 0x01 << ( pins[pin]->number );
		break;
		case pins[pin]->CAN_DIGITAL_TASK_HIGH:
		data[0] |= 0x01 << ( pins[pin]->number );
		data[1] |= 0x01 << ( pins[pin]->number );
		break;
		case pins[pin]->CAN_DIGITAL_TASK_LOW:
		data[0] |= 0x01 << ( pins[pin]->number );
		break;
		default:
			tasknull++;
			break;
		}
		pins[pin]->Task = pins[pin]->CAN_DIGITAL_TASK_NULL;
	}
	if(tasknull != 8)canWrite(slaveTaskId,2,data);
}

int  CanDigital::CanDigitalPin::assignPinNumber(int number,CanDigital *canDigital){
	this->canDigital = canDigital;
	this->number = number;

	Setup = CAN_DIGITAL_SETUP_NULL;
	Task = CAN_DIGITAL_TASK_NULL;
	pinState=0;
}

int CanDigital::CanDigitalPin::setupDigitalIn(){
	if(Setup == CAN_DIGITAL_SETUP_IN)return 0;
	else if(Setup != CAN_DIGITAL_SETUP_NULL)return 1;

	unsigned char data[8];
	data[0] = (0x01 << number);
	data[1] = CAN_DIGITAL_SETUP_IN;
	canDigital->canWrite(canDigital->slaveSetupId,2,data);

	Setup = CAN_DIGITAL_SETUP_PULLDOWN;
	return 0;

	while(Task!=CAN_DIGITAL_SETUP_IN && millis()-setupTimeOut < TIMEOUT);

	if(Task==CAN_DIGITAL_SETUP_IN){
		Setup = CAN_DIGITAL_SETUP_PULLDOWN;
		return 0;
	}else if(millis()-setupTimeOut >= TIMEOUT)
		return 1;
}

int CanDigital::CanDigitalPin::setupDigitalOut(){

	if(Setup == CAN_DIGITAL_SETUP_OUT)return 0;
	else if(Setup != CAN_DIGITAL_SETUP_NULL)return 1;

	unsigned char data[8];
	data[0] = (0x01 << number);
	data[1] = CAN_DIGITAL_SETUP_OUT;
	canDigital->canWrite(canDigital->slaveSetupId,2,data);

	Setup = CAN_DIGITAL_SETUP_OUT;
	return 0;

	setupTimeOut = millis();
	while(Task!=CAN_DIGITAL_SETUP_OUT && millis()-setupTimeOut < TIMEOUT);

	if(Task==CAN_DIGITAL_SETUP_OUT){
		Setup = CAN_DIGITAL_SETUP_OUT;
		return 0;
	}else if(millis()-setupTimeOut >= TIMEOUT)
		return 1;
}

int CanDigital::CanDigitalPin::setupDigitalInPullUp(){
	if(Setup == CAN_DIGITAL_SETUP_PULLUP)return 0;
	else if(Setup != CAN_DIGITAL_SETUP_NULL)return 1;

	unsigned char data[8];
	data[0] = (0x01 << number);
	data[1] = CAN_DIGITAL_SETUP_PULLUP;
	canDigital->canWrite(canDigital->slaveSetupId,2,data);

	Setup = CAN_DIGITAL_SETUP_PULLUP;
	return 0;

	setupTimeOut = millis();
	while(Task!=CAN_DIGITAL_SETUP_PULLUP && millis()-setupTimeOut < TIMEOUT);

	if(Task==CAN_DIGITAL_SETUP_PULLUP){
		Setup = CAN_DIGITAL_SETUP_PULLUP;
		return 0;
	}else if(millis()-setupTimeOut >= TIMEOUT)
		return 1;
}

int CanDigital::CanDigitalPin::setupDigitalInPullDown(){
	if(Setup == CAN_DIGITAL_SETUP_PULLDOWN)return 0;
	else if(Setup != CAN_DIGITAL_SETUP_NULL)return 1;

	unsigned char data[8];
	data[0] = (0x01 << number);
	data[1] = CAN_DIGITAL_SETUP_PULLDOWN;

	canDigital->canWrite(canDigital->slaveSetupId,2,data);

	Setup = CAN_DIGITAL_SETUP_PULLDOWN;
	return 0;

	setupTimeOut = millis();
	while(Task!=CAN_DIGITAL_SETUP_PULLDOWN && millis()-setupTimeOut < TIMEOUT);

	if(Task==CAN_DIGITAL_SETUP_PULLDOWN){
		Setup = CAN_DIGITAL_SETUP_PULLDOWN;

		return 0;
	}else if(millis()-setupTimeOut >= TIMEOUT)
		return 1;
}


void CanDigital::CanDigitalPin::digitalWrite(bool value){
	if(value){
		while(1);
		digitalHigh();
	}
	else digitalLow();
}

int CanDigital::CanDigitalPin::digitalRead(){
	if(   Setup == CAN_DIGITAL_SETUP_IN
			||Setup == CAN_DIGITAL_SETUP_PULLUP
			||Setup == CAN_DIGITAL_SETUP_PULLDOWN){

		Task = CAN_DIGITAL_TASK_READ;
		return pinState;


	}else return 2;

}

void CanDigital::CanDigitalPin::digitalHigh(){
	if(Setup == CAN_DIGITAL_SETUP_OUT){
		Task = CAN_DIGITAL_TASK_HIGH;
		pinState=1;
	}
}
void CanDigital::CanDigitalPin::digitalLow(){
	if(Setup == CAN_DIGITAL_SETUP_OUT){
		Task = CAN_DIGITAL_TASK_LOW;
		pinState=0;
	}
}
void CanDigital::CanDigitalPin::digitalToggle(){
	if(pinState)digitalLow();
	else digitalHigh();
}
