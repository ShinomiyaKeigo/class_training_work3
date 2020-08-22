#ifndef CAN_VOLTAGE_HPP
#define CAN_VOLTAGE_HPP

/*//////////////////////
 * Ver.Tourobo2019
 * Designed On 2019.08.24 By ShomaNakaaki
 *
////////////////////////*/

#include "layer_driver/base/can.hpp"
#include "util.h"

#define GAIN_L 1
#define GAIN_F 1
#define GAIN_R 1

class CanVoltage:public CanHandler{
public:
	CanVoltage(Can &can);
	int setup();
	int canRead(int id,int number,unsigned char data[8]);
	int canId(int id);
	int cycle();
	float voltage();
	float feedBack(int bldc_select);
private:
	float voltage_memory;
};

#endif
