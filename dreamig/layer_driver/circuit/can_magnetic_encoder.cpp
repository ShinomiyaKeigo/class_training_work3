#include "layer_driver/circuit/can_magnetic_encoder.hpp"

CanMagneticEncoder::CanMagneticEncoder(Can &can, int number, int cpr){
	id = CAN_MAGNETIC_ENCODER_ID + number;
	cprData = cpr;
	can.addHandler(this);
	bit = 0;
	deg = 0.0;
	rad = 0.0;
	flag = false;
	mirrorFlag=false;
}

int CanMagneticEncoder::setup(){//default=2ms
	unsigned char data[8] = {2};
	int error = canSetup();
	error += canSetId(id);
	int64_t time = millis();
	while(millis() - time <= 5000 && !flag){
		canWrite(id, 2, data);
		delay_ms(10);
	}
	if(flag) return 1;
	else return 0;
	return error;
}


int CanMagneticEncoder::setup(uint16_t send_time){
	unsigned char data[8] = {send_time};
	int error = canSetup();
	error += canSetId(id);
	int64_t time = millis();
	while(millis() - time <= 1000 && !flag){
		canWrite(id, 2, data);
		delay_ms(10);
	}
	if(flag) return 1;
	else return 0;
	return error;
}

void CanMagneticEncoder::cycle(){/*
	unsigned char data[8] = {0};
	canWrite(id, 2, data);
	if(mirrorFlag==true){bit=cprData-bit;}*/
}

void CanMagneticEncoder::mirror(bool mirrorFlag){
	this->mirrorFlag=mirrorFlag;
}

int CanMagneticEncoder::count(){
	flag = false;
	return bit;
}

float CanMagneticEncoder::degree(){
	flag = false;
	deg = (float)bit / 4095.0 * 360.0;
	return deg;
}

float CanMagneticEncoder::radian(){
	flag = false;
	rad = (float)bit / 4095.0 * 2.0 * M_PI;
	return rad;
}


bool CanMagneticEncoder::judge(){
	return flag;
}

int CanMagneticEncoder::canRead(int id, int number, unsigned char data[8]){
	bit = uchar4_to_int(data);
	if(mirrorFlag==true){bit=cprData-bit;}
	flag = true;
	return 0;
}

int CanMagneticEncoder::canId(int id){
	if(this->id == id)return 1;
	else return 0;
}




