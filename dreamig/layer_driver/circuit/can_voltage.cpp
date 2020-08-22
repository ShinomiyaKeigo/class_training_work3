#include "layer_driver/circuit/can_voltage.hpp"

CanVoltage::CanVoltage(Can &can){
	can.addHandler(this);
}

int CanVoltage::setup(){
	unsigned char sendData[8]{0};
	int error = canSetup();
	error += canSetId(0x710);
	canWrite(0x710,1,sendData);
	return error;
}

int CanVoltage::canRead(int id,int number,unsigned char data[8]){
	//if(id == 0x710){
	//printf("ok \n");
	voltage_memory = uchar4_to_float(&data[0]);
		//canWrite(0x30F,1,sendData);
	//}
	return 0;
}

int CanVoltage::canId(int id){
	if(id==0x710)return 1;
	//else if(id==0x300)return 1;//リターンした時点で自動でcanReadが実行される
	else return 0;
}

int CanVoltage::cycle(){
	unsigned char sendData[8]{0};
	canWrite(0x710,1,sendData);
	return 1;
}

float CanVoltage::voltage(){
	return voltage_memory;
}

float CanVoltage::feedBack(int bldc_select){//0:left 1:flont 2:right
	if(bldc_select == 0)return voltage_memory * GAIN_L;
	else if(bldc_select == 1)return voltage_memory * GAIN_F;
	else if(bldc_select == 2)return voltage_memory * GAIN_R;
}
