/**************************************************
 *
 **************************************************/
#ifndef CAN_DIGITAL_H_INCLUDED
#define CAN_DIGITAL_H_INCLUDED
/**************************************************
 * include
 **************************************************/
#include "layer_driver/base/digital.hpp"
#include "layer_driver/board/pin.hpp"
#include "layer_driver/base/can.hpp"

#include "layer_driver/base/util.h"
/**************************************************
 * define
 **************************************************/
#define CAN_DIGITAL_ID 0x500

#define TIMEOUT 1000//ms

class CanDigital:public CanHandler{

private:

		class CanDigitalPin:public Digital{
			friend class CanDigital;
		protected:
			int _digitalWrite(){};
			void _digitalWrite(int value){};
			int _digitalRead(){};
			int _setupDigitalIn(){};
			int _setupDigitalOut(){};
			int _setupDigitalInPullUp(){};
			int _setupDigitalInPullDown(){};
			//int _setupDigitalInterrupt(int interruptMode){return 1;};

		private:
			CanDigital *canDigital;
			int assignPinNumber(int number,CanDigital *canDigital);

			bool pinState;
			int number;
			unsigned char Setup,Task;

			int64_t setupTimeOut;
			enum{
					CAN_DIGITAL_SETUP_NULL=0,
					CAN_DIGITAL_SETUP_IN,
					CAN_DIGITAL_SETUP_OUT,
					CAN_DIGITAL_SETUP_PULLUP,
					CAN_DIGITAL_SETUP_PULLDOWN,

					CAN_DIGITAL_TASK_NULL,
					CAN_DIGITAL_TASK_READ,
					CAN_DIGITAL_TASK_HIGH,
					CAN_DIGITAL_TASK_LOW,
				};
		public:

			void digitalWrite(bool value);
			int digitalRead();
			int setupDigitalIn();
			int setupDigitalOut();
			int setupDigitalInPullUp();
			int setupDigitalInPullDown();

			void digitalHigh();
			void digitalLow();
			void digitalToggle();
		};
	CanDigitalPin *pins[8];

	int setupId,taskId,slaveSetupId,slaveTaskId;
	bool runSetupOnce,setupFlag;
	unsigned char readData;

	int canRead(int id,int number,unsigned char data[8]);
	int canId(int id);
public:

	CanDigital(Can &can,int number);
	int setup();
	void cycle();

	CanDigitalPin pin0;
	CanDigitalPin pin1;
	CanDigitalPin pin2;
	CanDigitalPin pin3;
	CanDigitalPin pin4;
	CanDigitalPin pin5;
	CanDigitalPin pin6;
	CanDigitalPin pin7;
};

#endif
