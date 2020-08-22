#include "layer_driver/circuit/can_led.hpp"

#if TEST == 2
CanLed::CanLed(Can &can, int number, unsigned short freq){
	id = CAN_LED_H + number;
	can.addHandler(this);
	this->freq = freq;

	led0.canStatus(0, this);
	led1.canStatus(1, this);
	led2.canStatus(2, this);
	led3.canStatus(3, this);
	led4.canStatus(4, this);
	led5.canStatus(5, this);
	led6.canStatus(6, this);
	led7.canStatus(7, this);
	led8.canStatus(8, this);
	led9.canStatus(9, this);
	led10.canStatus(10, this);
	led11.canStatus(11, this);
	led12.canStatus(12, this);
	led13.canStatus(13, this);
	led14.canStatus(14, this);
	led15.canStatus(15, this);

	leds[0] = &led0;
	leds[1] = &led1;
	leds[2] = &led2;
	leds[3] = &led3;
	leds[4] = &led4;
	leds[5] = &led5;
	leds[6] = &led6;
	leds[7] = &led7;
	leds[8] = &led8;
	leds[9] = &led9;
	leds[10] = &led10;
	leds[11] = &led11;
	leds[12] = &led12;
	leds[13] = &led13;
	leds[14] = &led14;
	leds[15] = &led15;

	task = TASK_NULL;

	timeStamp = millis();
}

int CanLed::setup(){
	if(canSetup()) return 1;
	canSetId(id);

	for(int i = 0; i < LED_NUM; i++)leds[i]->status = 0;
	clear();

	timeStamp = millis();
	return 0;
}

void CanLed::cycle(){
	unsigned char buf[8] = {0};

	if(task == TASK_NULL)return;
	else if(task == TASK_SEND){
		buf[0] = 0xff;
		buf[1] = buf_led.l;
		canWrite(CAN_LED_L, 2, buf);

		buf[0] = 0xff;
		buf[1] = buf_led.h;
		canWrite(CAN_LED_H, 2, buf);
	}

	task = TASK_NULL;
}

void CanLed::canLedTransmit(int id, int arg, unsigned char data[8]){canWrite(id, arg, data);}

int CanLed::CanLedPin::_setupDigitalOut(){
	canLed->setup();
	return 0;
}

int CanLed::CanLedPin::canStatus(int number, CanLed *canLed){
	this->canLed = canLed;
	this->number = number;
	return 0;
}

void CanLed::CanLedPin::digitalHigh(){
	unsigned char buf[8];
	bool f;

	if(number >= 8)f = 1;
	else f = 0;

	buf[0] = 0x01;
	if(!f)buf[0] = buf[0] << (7 - number);
	else buf[0] = buf[0] << (7 - (number-8));

	buf[1] = 0x01;
	if(!f)buf[1] = buf[1] << (7 - number);
	else buf[1] = buf[1] << (7 - (number-8));

	if(!digitalRead()){
		if(f)canLed->canLedTransmit(CAN_LED_H, 2, buf);
		else if(!f)canLed->canLedTransmit(CAN_LED_L, 2, buf);
	}
	status = 1;
	canLed->task = TASK_SEND;
}

void CanLed::CanLedPin::digitalLow(){
	unsigned char buf[8];
	bool f;

	if(number >= 8)f = 1;
	else f = 0;

	buf[0] = 0x01;
	if(!f)buf[0] = buf[0] << (7 - number);
	else buf[0] = buf[0] << (7 - (number-8));

	buf[1] = 0x00;
	if(!f)buf[1] = buf[1] << (7 - number);
	else buf[1] = buf[1] << (7 - (number-8));

	if(!_digitalRead()){
		if(f)canLed->canLedTransmit(CAN_LED_H, 2, buf);
		else if(!f)canLed->canLedTransmit(CAN_LED_L, 2, buf);
	}
	status = 0;
	canLed->task = TASK_SEND;
}

void CanLed::CanLedPin::_digitalWrite(int value){
	if(value == 0)digitalLow();
	else if(value == 1)digitalHigh();
}

void CanLed::CanLedPin::digitalToggle(){
	if(digitalRead())digitalLow();
	else digitalHigh();
}

void CanLed::led(unsigned short n){
	for(int i = 0; i < LED_NUM; i++){
		leds[i]->_digitalWrite((n & (0x0001 << i)));
		//if((n & (0x0001 << i)) != 0)leds[i]->digitalHigh();
		//else leds[i]->digital;
	}
}


#elif TEST == 1
CanLed::CanLed(Can &can, int number, unsigned short freq){
	id = CAN_LED_H + number;
	can.addHandler(this);
	this->freq = freq;

	led0.canStatus(0, this);
	led1.canStatus(1, this);
	led2.canStatus(2, this);
	led3.canStatus(3, this);
	led4.canStatus(4, this);
	led5.canStatus(5, this);
	led6.canStatus(6, this);
	led7.canStatus(7, this);
	led8.canStatus(8, this);
	led9.canStatus(9, this);
	led10.canStatus(10, this);
	led11.canStatus(11, this);
	led12.canStatus(12, this);
	led13.canStatus(13, this);
	led14.canStatus(14, this);
	led15.canStatus(15, this);

	leds[0] = &led0;
	leds[1] = &led1;
	leds[2] = &led2;
	leds[3] = &led3;
	leds[4] = &led4;
	leds[5] = &led5;
	leds[6] = &led6;
	leds[7] = &led7;
	leds[8] = &led8;
	leds[9] = &led9;
	leds[10] = &led10;
	leds[11] = &led11;
	leds[12] = &led12;
	leds[13] = &led13;
	leds[14] = &led14;
	leds[15] = &led15;

	task = TASK_NULL;

	timeStamp = millis();
}

int CanLed::setup(){
	if(canSetup()) return 1;
	canSetId(id);

	for(int i = 0; i < LED_NUM; i++)leds[i]->status = 0;
	clear();

	timeStamp = millis();
	return 0;
}

void CanLed::cycle(){
	unsigned char buf[8] = {0};

	if(task == TASK_NULL)return;
	else if(task == TASK_SEND){
		buf[0] = 0xff;
		buf[1] = buf_led.l;
		canWrite(CAN_LED_L, 2, buf);

		buf[0] = 0xff;
		buf[1] = buf_led.h;
		canWrite(CAN_LED_H, 2, buf);
	}

	task = TASK_NULL;
}

void CanLed::canLedTransmit(int id, int arg, unsigned char data[8]){canWrite(id, arg, data);}

int CanLed::CanLedPin::setup(){
	canLed->setup();
	return 0;
}

int CanLed::CanLedPin::canStatus(int number, CanLed *canLed){
	this->canLed = canLed;
	this->number = number;
	return 0;
}

void CanLed::CanLedPin::on(){
	unsigned char buf[8];
	bool f;

	if(number >= 8)f = 1;
	else f = 0;

	buf[0] = 0x01;
	if(!f)buf[0] = buf[0] << (7 - number);
	else buf[0] = buf[0] << (7 - (number-8));

	buf[1] = 0x01;
	if(!f)buf[1] = buf[1] << (7 - number);
	else buf[1] = buf[1] << (7 - (number-8));

	if(!read()){
		if(f)canLed->canLedTransmit(CAN_LED_H, 2, buf);
		else if(!f)canLed->canLedTransmit(CAN_LED_L, 2, buf);
	}
	status = 1;
	canLed->task = TASK_SEND;
}

void CanLed::CanLedPin::off(){
	unsigned char buf[8];
	bool f = 0;

	if(number >= 8)f = 1;
	else f = 0;

	buf[0] = 0x01;
	if(!f)buf[0] = buf[0] << (7 - number);
	else buf[0] = buf[0] << (7 - (number-8));

	buf[1] = 0x00;
	if(!f)buf[1] = buf[1] << (7 - number);
	else buf[1] = buf[1] << (7 - (number-8));

	if(read()){
		if(f)canLed->canLedTransmit(CAN_LED_H, 2, buf);
		else if(!f)canLed->canLedTransmit(CAN_LED_L, 2, buf);
	}
	status = 0;
	canLed->task = TASK_SEND;
}

void CanLed::CanLedPin::toggle(){
	if(!read())on();
	else off();
}

void CanLed::led(unsigned short n){
	for(int i = 0; i < LED_NUM; i++){
		if((n & (0x0001 << i)) != 0)leds[i]->on();
		else leds[i]->off();
	}
}
#endif
