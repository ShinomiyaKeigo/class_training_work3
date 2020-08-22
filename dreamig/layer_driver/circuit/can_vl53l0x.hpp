#ifndef CAN_VL53L0X_HPP
#define CAN_VL53L0X_HPP

#include "can.hpp"
#include "util.h"
#include "mcutime.h"

class CanVl53l0x:public CanHandler{
public:
	CanVl53l0x(Can &can,int number,unsigned short frequencyMillisArg);
	CanVl53l0x(Can &can,int number);
	int setup();
	int init_check();
	int value();//return mm
	int value_update_check();
	int canRead(int id,int number,unsigned char data[8]);
	int canId(int id);

private:
	uint8_t cycle_frequency;
	int errorFlag;
	int update_flag;
	uint16_t sens_value;
	uint64_t cycle_time;
	int id;
	bool init_flag;
};

#endif
