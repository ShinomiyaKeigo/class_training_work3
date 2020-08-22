#include "layer_driver/circuit/can_check.hpp"

CanCheck::CanCheck(Can &can, int number){
	id = CAN_CHECK_ID + number;
	can.addHandler(this);
	flag = false;
	ck = false;
}

int CanCheck::setup(){
	unsigned char data[8] = {0};
	int error = canSetup();
	error += canSetId(id);
	canWrite(id, 1, data);
	int64_t time = millis();
	while(millis() - time <= 1000 && !flag);
	if(flag) return 1;
	else return 0;
	return error;
}

int CanCheck::check(){
	bool f;
	if(ck){
		f = ck;
		unsigned char data[8] = {0};
		canWrite(id, 2, data);
		ck = false;
	}
	return f;
}


int CanCheck::canRead(int id, int number, unsigned char data[8]){
	ck = true;
	return 0;
}

int CanCheck::canId(int id){
	if(this->id == id)return 1;
	else return 0;
}
