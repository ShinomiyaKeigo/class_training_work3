#include "layer_driver/circuit/can_vl53l0x.hpp"

CanVl53l0x::CanVl53l0x(Can &can,int number,unsigned short frequency_millis_arg){
	id =0x700+number;
	//printf("\nid=0x%x\n",id);
	errorFlag = 0;
	sens_value = 0;
	update_flag = 0;
	cycle_time = millis();
	cycle_frequency = frequency_millis_arg;
	can.addHandler(this);
}

CanVl53l0x::CanVl53l0x(Can &can,int number){
	id =0x700+number;
	//printf("\nid=0x%x\n",id);
	errorFlag = 0;
	sens_value = 0;
	update_flag = 0;
	cycle_time = millis();
	cycle_frequency = 0;
	can.addHandler(this);
}

int CanVl53l0x::setup(){
	int error = canSetup();
	error += canSetId(id);
	errorFlag = 0;
	unsigned char send_data[8]={cycle_frequency,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
	canWrite(id,1,send_data);
	return error;
}

int CanVl53l0x::init_check(){
	if(init_flag == 0){
		unsigned char send_data[8]={cycle_frequency,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
		canWrite(id,1,send_data);
		return 0;//faild one more try
	}else
	{
		return 1;//success
	}

}

int CanVl53l0x::value(){
	return sens_value;
}

int CanVl53l0x::value_update_check(){
	return update_flag;
}

int CanVl53l0x::canRead(int read_id,int number,unsigned char data[8]){
	if(read_id == id){
		switch (number) {
			case 2:
				sens_value = uchar4_to_int(&data[0]);
				sens_value = sens_value << 8;
				sens_value += uchar4_to_int(&data[1]);
				update_flag = 1;
				break;
			default:
				unsigned char send_data[8]={cycle_frequency,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
				canWrite(id,1,send_data);
				break;
		}
	}
	return 0;
}


int CanVl53l0x::canId(int id){
	return (this->id==id);
}
