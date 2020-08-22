/**************************************************
 *
 **************************************************/
#ifndef CAN_LED_H_INCLUDED
#define CAN_LED_H_INCLUDED
/**************************************************
 * include
 **************************************************/
#include "layer_driver/circuit/led.hpp"
#include "layer_driver/board/pin.hpp"
#include "layer_driver/base/can.hpp"
/**************************************************
 * define
 **************************************************/
#define TEST	10

#define LED_NUM	16

#define CAN_LED_H		0x290
#define CAN_LED_L		0x291

#define CAN_SW_OPTION	0x700
#define CAN_SW_DATA		0x740

#define DEF_FREQ		65535

#define TIMEOUT_MS		1000

/**************************************************
 * CanLed class
 **************************************************/
#if TEST == 2
class CanLed:public CanHandler{
private:
	class CanLedPin:public Digital{
		friend class CanLed;
	public:
		/*int setup(void);
		void on();
		void off();
		void toggle();
		int read(){return status;}*/

		void digitalHigh();
		void digitalLow();
		void digitalToggle();
	private:
		CanLed *canLed;
		int status;
		int number;
		int canStatus(int canId, CanLed *canLed);

		int _digitalWrite(){};
		void _digitalWrite(int value);
		int _digitalRead(){return status;}
		int _setupDigitalIn(){};
		int _setupDigitalOut();
		int _setupDigitalInPullUp(){};
		int _setupDigitalInPullDown(){};
	};

	Can *can;
	int id;
	unsigned short freq;
	int64_t timeStamp;

	typedef struct{
		char h;
		char l;
	}LED;
	LED buf_led;

public:
	CanLed(Can &can, int number = 0, unsigned short freq = DEF_FREQ);
	int setup();
	void cycle();

	void canLedTransmit(int id, int arg, unsigned char data[8]);

	void led(unsigned short data);
	void ledAll(bool d){led(0xffff * d);}
	void clear(){ledAll(0);}

	int64_t lastReadTime();
	bool timeout();

	int canRead(int id,int number, unsigned char data[8]){};
	int canId(int id){};

	CanLedPin led0;
	CanLedPin led1;
	CanLedPin led2;
	CanLedPin led3;
	CanLedPin led4;
	CanLedPin led5;
	CanLedPin led6;
	CanLedPin led7;
	CanLedPin led8;
	CanLedPin led9;
	CanLedPin led10;
	CanLedPin led11;
	CanLedPin led12;
	CanLedPin led13;
	CanLedPin led14;
	CanLedPin led15;

	CanLedPin *leds[16];

	enum{
		TASK_NULL,
		TASK_SEND
	};
	int task;
};
#elif TEST == 1
class CanLed:public CanHandler{
private:
	class CanLedPin:public Led{
		friend class CanLed;
	public:
		int setup(void);
		void on();
		void off();
		void toggle();
		int read(){return status;}
	private:
		CanLed *canLed;
		int status;
		int number;
		int canStatus(int canId, CanLed *canLed);
	};

	Can *can;
	int id;
	unsigned short freq;
	int64_t timeStamp;

	typedef struct{
		char h;
		char l;
	}LED;
	LED buf_led;

public:
	CanLed(Can &can, int number = 0, unsigned short freq = DEF_FREQ);
	int setup();
	void cycle();

	void canLedTransmit(int id, int arg, unsigned char data[8]);

	void led(unsigned short data);
	void ledAll(bool d){led(0xffff * d);}
	void clear(){ledAll(0);}

	int64_t lastReadTime();
	bool timeout();

	int canRead(int id,int number, unsigned char data[8]){};
	int canId(int id){};

	CanLedPin led0;
	CanLedPin led1;
	CanLedPin led2;
	CanLedPin led3;
	CanLedPin led4;
	CanLedPin led5;
	CanLedPin led6;
	CanLedPin led7;
	CanLedPin led8;
	CanLedPin led9;
	CanLedPin led10;
	CanLedPin led11;
	CanLedPin led12;
	CanLedPin led13;
	CanLedPin led14;
	CanLedPin led15;

	CanLedPin *leds[16];

	enum{
		TASK_NULL,
		TASK_SEND
	};
	int task;
};

#endif
#endif
