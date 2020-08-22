#ifndef PIN_HPP_INCLUDED
#define PIN_HPP_INCLUDED

/*
�`���p���W�[�ł��킩��I
ichigoplus��h���C�o�̍���I

�����������H
�P�A�s���̔z�u��ς������@���@pin.cpp��
�Q�A�V�����s����ǉ��������@���@�P�S�s�ڂ�
�R�A�s�������������@���@�P�X�s�ڂ�
�S�A��̖��O���ς�����@���@pin.cpp��

�Q�C�V�����s����ǉ�������
�@�ǉ��������s���Ɠ����@�\�̃N���X�������R�s�[���ē\��t���A�N���X���������������ĉ������B
�@�Ⴆ�΁AD10����肽�����D0���R�s�[����D0���ď����Ă��镔����S��D10�ɒu�������銴���ŁB
�@�I�������pin.cpp�����ĉ������B

�R�C�s������������
�@���������s���̃N���X��S�������nĉ������B
�@�Ⴆ�΁AD10�������������class D10{...}; �Ƃ�����A�̃N���X�܂邲�Ə����ĉ������B
�@�I�������pin.cpp�����ĉ������B
 */

#ifdef __cplusplus
extern "C" void std_char_out(char data);
extern "C" void std_char_out_with_flush(char data);
extern "C" int std_char_out_setup();
extern "C" char* board_name();
#else
void std_char_out(char data);
void std_char_out_with_flush(char data);
int std_char_out_setup();
char* board_name();
#endif
#ifdef __cplusplus

#include "../../layer_driver/base/serial.hpp"
#include "../../layer_driver/base/digital.hpp"
#include "../../layer_driver/base/analog.hpp"
#include "../../layer_driver/base/encoder.hpp"
#include "../../layer_driver/base/pwm.hpp"
#include "../../layer_driver/base/i2c.hpp"
#include "../../layer_driver/base/spi.hpp"

extern "C"{
#include "./stm32f4_config/config_can.h"
#include "./stm32f4_config/config_gpio_interrupt.h"
}

//--- EMERGENCY SWITCH
class EmergencySwitch:public Digital{
private:
	int _digitalWrite();
	void _digitalWrite(int value);
	int _digitalRead();
	int _setupDigitalIn();
	int _setupDigitalOut();
	int _setupDigitalInPullUp();
	int _setupDigitalInPullDown();
public:

	Digital& operator= (int value) {
		digitalWrite(value);
		return *this;
	}

	Digital& operator= (Digital& dig) {
		digitalWrite(dig.digitalRead());
		return *this;
	}

	operator int() {
		return digitalRead();
	}
};

//--- EMERGENCY READ
class EmergencyRead:public Digital{
private:
	int _digitalWrite();
	void _digitalWrite(int value);
	int _digitalRead();
	int _setupDigitalIn();
	int _setupDigitalOut();
	int _setupDigitalInPullUp();
	int _setupDigitalInPullDown();
public:

	Digital& operator= (int value) {
		digitalWrite(value);
		return *this;
	}

	Digital& operator= (Digital& dig) {
		digitalWrite(dig.digitalRead());
		return *this;
	}

	operator int() {
		return digitalRead();
	}
};

//--- LCD BACK LIGHT
class LCDBackLight:public Digital{
private:
	int _digitalWrite();
	void _digitalWrite(int value);
	int _digitalRead();
	int _setupDigitalIn();
	int _setupDigitalOut();
	int _setupDigitalInPullUp();
	int _setupDigitalInPullDown();
public:

	Digital& operator= (int value) {
		digitalWrite(value);
		return *this;
	}

	Digital& operator= (Digital& dig) {
		digitalWrite(dig.digitalRead());
		return *this;
	}

	operator int() {
		return digitalRead();
	}
};

class ResetLed:public Digital{
private:
	int _digitalWrite();
	void _digitalWrite(int value);
	int _digitalRead();
	int _setupDigitalIn();
	int _setupDigitalOut();
	int _setupDigitalInPullUp();
	int _setupDigitalInPullDown();
public:

	Digital& operator= (int value) {
		digitalWrite(value);
		return *this;
	}

	Digital& operator= (Digital& dig) {
		digitalWrite(dig.digitalRead());
		return *this;
	}

	operator int() {
		return digitalRead();
	}
};

class A0:public Digital,public Analog{
private:
	enum{
		MODE_NULL,
		MODE_ANALOG,
		MODE_DIGITAL
	};
	int mode;

	int _digitalWrite();
	void _digitalWrite(int value);
	int _digitalRead();
	int _setupDigitalIn();
	int _setupDigitalOut();
	int _setupDigitalInPullUp();
	int _setupDigitalInPullDown();

	int _setupAnalogIn();
	float _analogRead();
public:
	A0(){mode=0;};

	int analogResolution(){return 4095;};
	float analogVoltage(){return 3.3;};

	Digital& operator= (int value) {
		digitalWrite(value);
		return *this;
	}

	Digital& operator= (Digital& dig) {
		digitalWrite(dig.digitalRead());
		return *this;
	}

	operator bool(){
		return digitalRead();
	}

	operator int() {
		return digitalRead();
	}

	operator float() {
		return analogRead();
	}

};

class A1:public Digital,public Analog{
private:
	enum{
		MODE_NULL,
		MODE_ANALOG,
		MODE_DIGITAL
	};
	int mode;
	int _digitalWrite();
	void _digitalWrite(int value);
	int _digitalRead();
	int _setupDigitalIn();
	int _setupDigitalOut();
	int _setupDigitalInPullUp();
	int _setupDigitalInPullDown();

	int _setupAnalogIn();
	float _analogRead();
public:
	A1(){mode=0;};

	int analogResolution(){return 4095;};
	float analogVoltage(){return 3.3;};
	Digital& operator= (int value) {
		digitalWrite(value);
		return *this;
	}

	Digital& operator= (Digital& dig) {
		digitalWrite(dig.digitalRead());
		return *this;
	}

	operator bool(){
		return digitalRead();
	}

	operator int() {
		return digitalRead();
	}

	operator float() {
		return analogRead();
	}
};

class A2:public Digital,public Analog{
private:
	enum{
		MODE_NULL,
		MODE_ANALOG,
		MODE_DIGITAL
	};
	int mode;
	int _digitalWrite();
	void _digitalWrite(int value);
	int _digitalRead();
	int _setupDigitalIn();
	int _setupDigitalOut();
	int _setupDigitalInPullUp();
	int _setupDigitalInPullDown();

	int _setupAnalogIn();
	float _analogRead();
public:
	A2(){mode=0;};

	int analogResolution(){return 4095;};
	float analogVoltage(){return 3.3;};
	Digital& operator= (int value) {
		digitalWrite(value);
		return *this;
	}

	Digital& operator= (Digital& dig) {
		digitalWrite(dig.digitalRead());
		return *this;
	}

	operator bool(){
		return digitalRead();
	}

	operator int() {
		return digitalRead();
	}

	operator float() {
		return analogRead();
	}
};

class A3:public Digital,public Analog{
private:
	enum{
		MODE_NULL,
		MODE_ANALOG,
		MODE_DIGITAL
	};
	int mode;
	int _digitalWrite();
	void _digitalWrite(int value);
	int _digitalRead();
	int _setupDigitalIn();
	int _setupDigitalOut();
	int _setupDigitalInPullUp();
	int _setupDigitalInPullDown();

	int _setupAnalogIn();
	float _analogRead();
public:
	A3(){mode=0;};

	int analogResolution(){return 4095;};
	float analogVoltage(){return 3.3;};
	Digital& operator= (int value) {
		digitalWrite(value);
		return *this;
	}

	Digital& operator= (Digital& dig) {
		digitalWrite(dig.digitalRead());
		return *this;
	}

	operator bool(){
		return digitalRead();
	}

	operator int() {
		return digitalRead();
	}

	operator float() {
		return analogRead();
	}
};

class A4:public Digital,public Analog{
private:
	enum{
		MODE_NULL,
		MODE_ANALOG,
		MODE_DIGITAL
	};
	int mode;

	int _digitalWrite();
	void _digitalWrite(int value);
	int _digitalRead();
	int _setupDigitalIn();
	int _setupDigitalOut();
	int _setupDigitalInPullUp();
	int _setupDigitalInPullDown();

	int _setupAnalogIn();
	float _analogRead();
public:
	A4(){mode=0;};

	int analogResolution(){return 4095;};
	float analogVoltage(){return 3.3;};

	Digital& operator= (int value) {
		digitalWrite(value);
		return *this;
	}

	Digital& operator= (Digital& dig) {
		digitalWrite(dig.digitalRead());
		return *this;
	}

	operator bool(){
		return digitalRead();
	}

	operator int() {
		return digitalRead();
	}

	operator float() {
		return analogRead();
	}

};

class A5:public Digital,public Analog{
private:
	enum{
		MODE_NULL,
		MODE_ANALOG,
		MODE_DIGITAL
	};
	int mode;
	int _digitalWrite();
	void _digitalWrite(int value);
	int _digitalRead();
	int _setupDigitalIn();
	int _setupDigitalOut();
	int _setupDigitalInPullUp();
	int _setupDigitalInPullDown();

	int _setupAnalogIn();
	float _analogRead();
public:
	A5(){mode=0;};

	int analogResolution(){return 4095;};
	float analogVoltage(){return 3.3;};
	Digital& operator= (int value) {
		digitalWrite(value);
		return *this;
	}

	Digital& operator= (Digital& dig) {
		digitalWrite(dig.digitalRead());
		return *this;
	}

	operator bool(){
		return digitalRead();
	}

	operator int() {
		return digitalRead();
	}

	operator float() {
		return analogRead();
	}
};

class A6:public Digital,public Analog{
private:
	enum{
		MODE_NULL,
		MODE_ANALOG,
		MODE_DIGITAL
	};
	int mode;
	int _digitalWrite();
	void _digitalWrite(int value);
	int _digitalRead();
	int _setupDigitalIn();
	int _setupDigitalOut();
	int _setupDigitalInPullUp();
	int _setupDigitalInPullDown();

	int _setupAnalogIn();
	float _analogRead();
public:
	A6(){mode=0;};

	int analogResolution(){return 4095;};
	float analogVoltage(){return 3.3;};
	Digital& operator= (int value) {
		digitalWrite(value);
		return *this;
	}

	Digital& operator= (Digital& dig) {
		digitalWrite(dig.digitalRead());
		return *this;
	}

	operator bool(){
		return digitalRead();
	}

	operator int() {
		return digitalRead();
	}

	operator float() {
		return analogRead();
	}
};

class A7:public Digital,public Analog{
private:
	enum{
		MODE_NULL,
		MODE_ANALOG,
		MODE_DIGITAL
	};
	int mode;
	int _digitalWrite();
	void _digitalWrite(int value);
	int _digitalRead();
	int _setupDigitalIn();
	int _setupDigitalOut();
	int _setupDigitalInPullUp();
	int _setupDigitalInPullDown();

	int _setupAnalogIn();
	float _analogRead();
public:
	A7(){mode=0;};

	int analogResolution(){return 4095;};
	float analogVoltage(){return 3.3;};
	Digital& operator= (int value) {
		digitalWrite(value);
		return *this;
	}

	Digital& operator= (Digital& dig) {
		digitalWrite(dig.digitalRead());
		return *this;
	}

	operator bool(){
		return digitalRead();
	}

	operator int() {
		return digitalRead();
	}

	operator float() {
		return analogRead();
	}
};

class A8:public Digital,public Analog{
private:
	enum{
		MODE_NULL,
		MODE_ANALOG,
		MODE_DIGITAL
	};
	int mode;

	int _digitalWrite();
	void _digitalWrite(int value);
	int _digitalRead();
	int _setupDigitalIn();
	int _setupDigitalOut();
	int _setupDigitalInPullUp();
	int _setupDigitalInPullDown();

	int _setupAnalogIn();
	float _analogRead();
public:
	A8(){mode=0;};

	int analogResolution(){return 4095;};
	float analogVoltage(){return 3.3;};

	Digital& operator= (int value) {
		digitalWrite(value);
		return *this;
	}

	Digital& operator= (Digital& dig) {
		digitalWrite(dig.digitalRead());
		return *this;
	}

	operator bool(){
		return digitalRead();
	}

	operator int() {
		return digitalRead();
	}

	operator float() {
		return analogRead();
	}

};

class A9:public Digital,public Analog{
private:
	enum{
		MODE_NULL,
		MODE_ANALOG,
		MODE_DIGITAL
	};
	int mode;
	int _digitalWrite();
	void _digitalWrite(int value);
	int _digitalRead();
	int _setupDigitalIn();
	int _setupDigitalOut();
	int _setupDigitalInPullUp();
	int _setupDigitalInPullDown();

	int _setupAnalogIn();
	float _analogRead();
public:
	A9(){mode=0;};

	int analogResolution(){return 4095;};
	float analogVoltage(){return 3.3;};
	Digital& operator= (int value) {
		digitalWrite(value);
		return *this;
	}

	Digital& operator= (Digital& dig) {
		digitalWrite(dig.digitalRead());
		return *this;
	}

	operator bool(){
		return digitalRead();
	}

	operator int() {
		return digitalRead();
	}

	operator float() {
		return analogRead();
	}
};

//////////////////////////////
class Red:public Digital,public Pwm{
private:
	enum{
		MODE_NULL,
		MODE_PWM,
		MODE_DIGITAL
	};
	int mode;
	int _digitalWrite();
	void _digitalWrite(int value);
	int _digitalRead();
	int _setupDigitalIn();
	int _setupDigitalOut();
	int _setupDigitalInPullUp();
	int _setupDigitalInPullDown();

	int _setupPwmOut(float frequency,float duty);
	void _pwmWrite(float duty);
	float _pwmWrite();
public:
	Red(){mode=0;}

	Digital& operator= (int value) {
		digitalWrite(value);
		return *this;
	}

	Digital& operator= (Digital& dig) {
		digitalWrite(dig.digitalRead());
		return *this;
	}

	Pwm& operator= (float value) {
		pwmWrite(value);
		return *this;
	}

	Pwm& operator= (Pwm& pwm) {
		pwm.pwmWrite(pwm.pwmWrite());
		return *this;
	}

	operator bool(){
		return digitalRead();
	}

	operator int() {
		return digitalRead();
	}

	operator float() {
		if (mode==MODE_PWM)return pwmWrite();
		else return 0.0;
	}
};

//////////////////////////////
//////////////////////////////
//////////////////////////////
//////////////////////////////
class Green:public Digital,public Pwm{
private:
	enum{
		MODE_NULL,
		MODE_PWM,
		MODE_DIGITAL
	};
	int mode;
	int _digitalWrite();
	void _digitalWrite(int value);
	int _digitalRead();
	int _setupDigitalIn();
	int _setupDigitalOut();
	int _setupDigitalInPullUp();
	int _setupDigitalInPullDown();

	int _setupPwmOut(float frequency,float duty);
	void _pwmWrite(float duty);
	float _pwmWrite();
public:
	Green(){mode=0;}

	Digital& operator= (int value) {
		digitalWrite(value);
		return *this;
	}

	Digital& operator= (Digital& dig) {
		digitalWrite(dig.digitalRead());
		return *this;
	}

	Pwm& operator= (float value) {
		pwmWrite(value);
		return *this;
	}

	Pwm& operator= (Pwm& pwm) {
		pwm.pwmWrite(pwm.pwmWrite());
		return *this;
	}

	operator bool(){
		return digitalRead();
	}

	operator int() {
		return digitalRead();
	}

	operator float() {
		if (mode==MODE_PWM)return pwmWrite();
		else return 0.0;
	}
};

//////////////////////////////
//////////////////////////////
class Blue:public Digital,public Pwm{
private:
	enum{
		MODE_NULL,
		MODE_PWM,
		MODE_DIGITAL
	};
	int mode;
	int _digitalWrite();
	void _digitalWrite(int value);
	int _digitalRead();
	int _setupDigitalIn();
	int _setupDigitalOut();
	int _setupDigitalInPullUp();
	int _setupDigitalInPullDown();

	int _setupPwmOut(float frequency,float duty);
	void _pwmWrite(float duty);
	float _pwmWrite();
public:
	Blue(){mode=0;}

	Digital& operator= (int value) {
		digitalWrite(value);
		return *this;
	}

	Digital& operator= (Digital& dig) {
		digitalWrite(dig.digitalRead());
		return *this;
	}

	Pwm& operator= (float value) {
		pwmWrite(value);
		return *this;
	}

	Pwm& operator= (Pwm& pwm) {
		pwm.pwmWrite(pwm.pwmWrite());
		return *this;
	}

	operator bool(){
		return digitalRead();
	}

	operator int() {
		return digitalRead();
	}

	operator float() {
		if (mode==MODE_PWM)return pwmWrite();
		else return 0.0;
	}
};

class Led0:public Digital{
private:
	int _digitalWrite();
	void _digitalWrite(int value);
	int _digitalRead();
	int _setupDigitalIn();
	int _setupDigitalOut();
	int _setupDigitalInPullUp();
	int _setupDigitalInPullDown();
	int _setupDigitalInterrupt(int interruptMode);
public:
	int line;
	Led0();
	int addInterruptHandler(DigitalInterruptHandler &handler);
	void interrupt();
	void stopInterrupt();
	Digital& operator= (int value) {
		digitalWrite(value);
		return *this;
	}

	Digital& operator= (Digital& dig) {
		digitalWrite(dig.digitalRead());
		return *this;
	}

	operator int() {
		return digitalRead();
	}
};
class Led1:public Digital{
private:
	int _digitalWrite();
	void _digitalWrite(int value);
	int _digitalRead();
	int _setupDigitalIn();
	int _setupDigitalOut();
	int _setupDigitalInPullUp();
	int _setupDigitalInPullDown();
	int _setupDigitalInterrupt(int interruptMode);
public:
	int line;
	Led1();
	int addInterruptHandler(DigitalInterruptHandler &handler);
	void interrupt();
	void stopInterrupt();
	Digital& operator= (int value) {
		digitalWrite(value);
		return *this;
	}

	Digital& operator= (Digital& dig) {
		digitalWrite(dig.digitalRead());
		return *this;
	}

	operator int() {
		return digitalRead();
	}
};
class Led2:public Digital{
private:
	int _digitalWrite();
	void _digitalWrite(int value);
	int _digitalRead();
	int _setupDigitalIn();
	int _setupDigitalOut();
	int _setupDigitalInPullUp();
	int _setupDigitalInPullDown();
	int _setupDigitalInterrupt(int interruptMode);
public:
	int line;
	Led2();
	int addInterruptHandler(DigitalInterruptHandler &handler);
	void interrupt();
	void stopInterrupt();
	Digital& operator= (int value) {
		digitalWrite(value);
		return *this;
	}

	Digital& operator= (Digital& dig) {
		digitalWrite(dig.digitalRead());
		return *this;
	}

	operator int() {
		return digitalRead();
	}
};
class Led3:public Digital{
private:
	int _digitalWrite();
	void _digitalWrite(int value);
	int _digitalRead();
	int _setupDigitalIn();
	int _setupDigitalOut();
	int _setupDigitalInPullUp();
	int _setupDigitalInPullDown();
	int _setupDigitalInterrupt(int interruptMode);
public:
	int line;
	Led3();
	int addInterruptHandler(DigitalInterruptHandler &handler);
	void interrupt();
	void stopInterrupt();
	Digital& operator= (int value) {
		digitalWrite(value);
		return *this;
	}

	Digital& operator= (Digital& dig) {
		digitalWrite(dig.digitalRead());
		return *this;
	}

	operator int() {
		return digitalRead();
	}
};
class Led4:public Digital{
private:
	int _digitalWrite();
	void _digitalWrite(int value);
	int _digitalRead();
	int _setupDigitalIn();
	int _setupDigitalOut();
	int _setupDigitalInPullUp();
	int _setupDigitalInPullDown();
	int _setupDigitalInterrupt(int interruptMode);
public:
	int line;
	Led4();
	int addInterruptHandler(DigitalInterruptHandler &handler);
	void interrupt();
	void stopInterrupt();
	Digital& operator= (int value) {
		digitalWrite(value);
		return *this;
	}

	Digital& operator= (Digital& dig) {
		digitalWrite(dig.digitalRead());
		return *this;
	}

	operator int() {
		return digitalRead();
	}
};
class Led5:public Digital{
private:
	int _digitalWrite();
	void _digitalWrite(int value);
	int _digitalRead();
	int _setupDigitalIn();
	int _setupDigitalOut();
	int _setupDigitalInPullUp();
	int _setupDigitalInPullDown();
	int _setupDigitalInterrupt(int interruptMode);
public:
	int line;
	Led5();
	int addInterruptHandler(DigitalInterruptHandler &handler);
	void interrupt();
	void stopInterrupt();
	Digital& operator= (int value) {
		digitalWrite(value);
		return *this;
	}

	Digital& operator= (Digital& dig) {
		digitalWrite(dig.digitalRead());
		return *this;
	}

	operator int() {
		return digitalRead();
	}
};

class D0:public Digital{
private:
	int _digitalWrite();
	void _digitalWrite(int value);
	int _digitalRead();
	int _setupDigitalIn();
	int _setupDigitalOut();
	int _setupDigitalInPullUp();
	int _setupDigitalInPullDown();
	int _setupDigitalInterrupt(int interruptMode);
public:
	int line;
	D0();
	int addInterruptHandler(DigitalInterruptHandler &handler);
	void interrupt();
	void stopInterrupt();
	Digital& operator= (int value) {
		digitalWrite(value);
		return *this;
	}

	Digital& operator= (Digital& dig) {
		digitalWrite(dig.digitalRead());
		return *this;
	}

	operator int() {
		return digitalRead();
	}
};

class D1:public Digital{
private:
	int _digitalWrite();
	void _digitalWrite(int value);
	int _digitalRead();
	int _setupDigitalIn();
	int _setupDigitalOut();
	int _setupDigitalInPullUp();
	int _setupDigitalInPullDown();

	int _setupDigitalInterrupt(int interruptMode);
public:
	int line;
	D1();
	int addInterruptHandler(DigitalInterruptHandler &handler);
	void stopInterrupt();
	Digital& operator= (int value) {
		digitalWrite(value);
		return *this;
	}

	Digital& operator= (Digital& dig) {
		digitalWrite(dig.digitalRead());
		return *this;
	}

	operator int() {
		return digitalRead();
	}
};

class D2:public Digital{
private:
	int _digitalWrite();
	void _digitalWrite(int value);
	int _digitalRead();
	int _setupDigitalIn();
	int _setupDigitalOut();
	int _setupDigitalInPullUp();
	int _setupDigitalInPullDown();
	int _setupDigitalInterrupt(int interruptMode);
public:
	int line;
	D2();
	int addInterruptHandler(DigitalInterruptHandler &handler);
	void stopInterrupt();
	Digital& operator= (int value){
		digitalWrite(value);
		return *this;
	}

	Digital& operator= (Digital& dig) {
		digitalWrite(dig.digitalRead());
		return *this;
	}

	operator int() {
		return digitalRead();
	}
};

class D3:public Digital{
private:
	int _digitalWrite();
	void _digitalWrite(int value);
	int _digitalRead();
	int _setupDigitalIn();
	int _setupDigitalOut();
	int _setupDigitalInPullUp();
	int _setupDigitalInPullDown();
	int _setupDigitalInterrupt(int interruptMode);
public:
	int line;
	D3();
	int addInterruptHandler(DigitalInterruptHandler &handler);
	void stopInterrupt();
	Digital& operator= (int value) {
		digitalWrite(value);
		return *this;
	}

	Digital& operator= (Digital& dig) {
		digitalWrite(dig.digitalRead());
		return *this;
	}

	operator int() {
		return digitalRead();
	}
};

class D5v0:public Digital{
private:
	int _digitalWrite();
	void _digitalWrite(int value);
	int _digitalRead();
	int _setupDigitalIn();
	int _setupDigitalOut();
	int _setupDigitalInPullUp();
	int _setupDigitalInPullDown();

	int _setupDigitalInterrupt(int interruptMode);
public:
	int line;
	D5v0();
	int addInterruptHandler(DigitalInterruptHandler &handler);
	void stopInterrupt();
	Digital& operator= (int value) {
		digitalWrite(value);
		return *this;
	}

	Digital& operator= (Digital& dig) {
		digitalWrite(dig.digitalRead());
		return *this;
	}

	operator int() {
		return digitalRead();
	}
};

class D5v1:public Digital{
private:
	int _digitalWrite();
	void _digitalWrite(int value);
	int _digitalRead();
	int _setupDigitalIn();
	int _setupDigitalOut();
	int _setupDigitalInPullUp();
	int _setupDigitalInPullDown();

	int _setupDigitalInterrupt(int interruptMode);
public:
	int line;
	D5v1();
	int addInterruptHandler(DigitalInterruptHandler &handler);
	void stopInterrupt();
	Digital& operator= (int value) {
		digitalWrite(value);
		return *this;
	}

	Digital& operator= (Digital& dig) {
		digitalWrite(dig.digitalRead());
		return *this;
	}

	operator int() {
		return digitalRead();
	}
};

class D5v2:public Digital{
private:
	int _digitalWrite();
	void _digitalWrite(int value);
	int _digitalRead();
	int _setupDigitalIn();
	int _setupDigitalOut();
	int _setupDigitalInPullUp();
	int _setupDigitalInPullDown();

	int _setupDigitalInterrupt(int interruptMode);
public:
	int line;
	D5v2();
	int addInterruptHandler(DigitalInterruptHandler &handler);
	void stopInterrupt();
	Digital& operator= (int value) {
		digitalWrite(value);
		return *this;
	}

	Digital& operator= (Digital& dig) {
		digitalWrite(dig.digitalRead());
		return *this;
	}

	operator int() {
		return digitalRead();
	}
};

class D5v3:public Digital{
private:
	int _digitalWrite();
	void _digitalWrite(int value);
	int _digitalRead();
	int _setupDigitalIn();
	int _setupDigitalOut();
	int _setupDigitalInPullUp();
	int _setupDigitalInPullDown();

	int _setupDigitalInterrupt(int interruptMode);
public:
	int line;
	D5v3();
	int addInterruptHandler(DigitalInterruptHandler &handler);
	void stopInterrupt();
	Digital& operator= (int value) {
		digitalWrite(value);
		return *this;
	}

	Digital& operator= (Digital& dig) {
		digitalWrite(dig.digitalRead());
		return *this;
	}

	operator int() {
		return digitalRead();
	}
};

class DataHold:public Digital{
private:
	int _digitalWrite();
	void _digitalWrite(int value);
	int _digitalRead();
	int _setupDigitalIn();
	int _setupDigitalOut();
	int _setupDigitalInPullUp();
	int _setupDigitalInPullDown();
public:

	Digital& operator= (int value) {
		digitalWrite(value);
		return *this;
	}

	Digital& operator= (Digital& dig) {
		digitalWrite(dig.digitalRead());
		return *this;
	}

	operator int() {
		return digitalRead();
	}
};

class WriteProtect:public Digital{
private:
	int _digitalWrite();
	void _digitalWrite(int value);
	int _digitalRead();
	int _setupDigitalIn();
	int _setupDigitalOut();
	int _setupDigitalInPullUp();
	int _setupDigitalInPullDown();
public:

	Digital& operator= (int value) {
		digitalWrite(value);
		return *this;
	}

	Digital& operator= (Digital& dig) {
		digitalWrite(dig.digitalRead());
		return *this;
	}

	operator int() {
		return digitalRead();
	}
};

class ChipSelect:public Digital{
private:
	int _digitalWrite();
	void _digitalWrite(int value);
	int _digitalRead();
	int _setupDigitalIn();
	int _setupDigitalOut();
	int _setupDigitalInPullUp();
	int _setupDigitalInPullDown();
public:

	Digital& operator= (int value) {
		digitalWrite(value);
		return *this;
	}

	Digital& operator= (Digital& dig) {
		digitalWrite(dig.digitalRead());
		return *this;
	}

	operator int() {
		return digitalRead();
	}
};

class Sw0:public Digital{
private:
	int _digitalWrite();
	void _digitalWrite(int value);
	int _digitalRead();
	int _setupDigitalIn();
	int _setupDigitalOut();
	int _setupDigitalInPullUp();
	int _setupDigitalInPullDown();
public:
	int line;
	Sw0();
	Digital& operator= (int value) {
		digitalWrite(value);
		return *this;
	}

	Digital& operator= (Digital& dig) {
		digitalWrite(dig.digitalRead());
		return *this;
	}

	operator int() {
		return digitalRead();
	}
};

class Sw1:public Digital{
private:
	int _digitalWrite();
	void _digitalWrite(int value);
	int _digitalRead();
	int _setupDigitalIn();
	int _setupDigitalOut();
	int _setupDigitalInPullUp();
	int _setupDigitalInPullDown();
public:
	int line;
	Sw1();
	Digital& operator= (int value) {
		digitalWrite(value);
		return *this;
	}

	Digital& operator= (Digital& dig) {
		digitalWrite(dig.digitalRead());
		return *this;
	}

	operator int() {
		return digitalRead();
	}
};

class Sw2:public Digital{
private:
	int _digitalWrite();
	void _digitalWrite(int value);
	int _digitalRead();
	int _setupDigitalIn();
	int _setupDigitalOut();
	int _setupDigitalInPullUp();
	int _setupDigitalInPullDown();
public:
	int line;
	Sw2();
	Digital& operator= (int value) {
		digitalWrite(value);
		return *this;
	}

	Digital& operator= (Digital& dig) {
		digitalWrite(dig.digitalRead());
		return *this;
	}

	operator int() {
		return digitalRead();
	}
};

class Sw3:public Digital{
private:
	int _digitalWrite();
	void _digitalWrite(int value);
	int _digitalRead();
	int _setupDigitalIn();
	int _setupDigitalOut();
	int _setupDigitalInPullUp();
	int _setupDigitalInPullDown();
public:
	int line;
	Sw3();
	Digital& operator= (int value) {
		digitalWrite(value);
		return *this;
	}

	Digital& operator= (Digital& dig) {
		digitalWrite(dig.digitalRead());
		return *this;
	}

	operator int() {
		return digitalRead();
	}
};

class Pwm0:public Digital,public Pwm{
private:
	enum{
		MODE_NULL,
		MODE_PWM,
		MODE_DIGITAL
	};
	int mode;
	int _digitalWrite();
	void _digitalWrite(int value);
	int _digitalRead();
	int _setupDigitalIn();
	int _setupDigitalOut();
	int _setupDigitalInPullUp();
	int _setupDigitalInPullDown();

	int _setupPwmOut(float frequency,float duty);
	void _pwmWrite(float duty);
	float _pwmWrite();
public:
	Pwm0(){mode=0;}

	Digital& operator= (int value) {
		digitalWrite(value);
		return *this;
	}

	Digital& operator= (Digital& dig) {
		digitalWrite(dig.digitalRead());
		return *this;
	}

	Pwm& operator= (float value) {
		pwmWrite(value);
		return *this;
	}

	Pwm& operator= (Pwm& pwm) {
		pwm.pwmWrite(pwm.pwmWrite());
		return *this;
	}

	operator bool(){
		return digitalRead();
	}

	operator int() {
		return digitalRead();
	}

	operator float() {
		if (mode==MODE_PWM)return pwmWrite();
		else return 0.0;
	}
};

class Pwm1:public Digital,public Pwm{
private:
	enum{
		MODE_NULL,
		MODE_PWM,
		MODE_DIGITAL
	};
	int mode;
	int _digitalWrite();
	void _digitalWrite(int value);
	int _digitalRead();
	int _setupDigitalIn();
	int _setupDigitalOut();
	int _setupDigitalInPullUp();
	int _setupDigitalInPullDown();

	int _setupPwmOut(float frequency,float duty);
	void _pwmWrite(float duty);
	float _pwmWrite();
public:
	Pwm1(){mode=0;}

	Digital& operator= (int value) {
		digitalWrite(value);
		return *this;
	}

	Digital& operator= (Digital& dig) {
		digitalWrite(dig.digitalRead());
		return *this;
	}

	Pwm& operator= (float value) {
		pwmWrite(value);
		return *this;
	}

	Pwm& operator= (Pwm& pwm) {
		pwm.pwmWrite(pwm.pwmWrite());
		return *this;
	}

	operator bool(){
		return digitalRead();
	}

	operator int() {
		return digitalRead();
	}

	operator float() {
		if (mode==MODE_PWM)return pwmWrite();
		else return 0.0;
	}
};

class Pwm2:public Digital,public Pwm{
private:
	enum{
		MODE_NULL,
		MODE_PWM,
		MODE_DIGITAL
	};
	int mode;
	int _digitalWrite();
	void _digitalWrite(int value);
	int _digitalRead();
	int _setupDigitalIn();
	int _setupDigitalOut();
	int _setupDigitalInPullUp();
	int _setupDigitalInPullDown();

	int _setupPwmOut(float frequency,float duty);
	void _pwmWrite(float duty);
	float _pwmWrite();
public:
	Pwm2(){mode=0;}

	Digital& operator= (int value) {
		digitalWrite(value);
		return *this;
	}

	Digital& operator= (Digital& dig) {
		digitalWrite(dig.digitalRead());
		return *this;
	}

	Pwm& operator= (float value) {
		pwmWrite(value);
		return *this;
	}

	Pwm& operator= (Pwm& pwm) {
		pwm.pwmWrite(pwm.pwmWrite());
		return *this;
	}

	operator bool(){
		return digitalRead();
	}

	operator int() {
		return digitalRead();
	}

	operator float() {
		if (mode==MODE_PWM)return pwmWrite();
		else return 0.0;
	}
};
class Pwm3:public Digital,public Pwm{
private:
	enum{
		MODE_NULL,
		MODE_PWM,
		MODE_DIGITAL
	};
	int mode;
	int _digitalWrite();
	void _digitalWrite(int value);
	int _digitalRead();
	int _setupDigitalIn();
	int _setupDigitalOut();
	int _setupDigitalInPullUp();
	int _setupDigitalInPullDown();

	int _setupPwmOut(float frequency,float duty);
	void _pwmWrite(float duty);
	float _pwmWrite();
public:
	Pwm3(){mode=0;}

	Digital& operator= (int value) {
		digitalWrite(value);
		return *this;
	}

	Digital& operator= (Digital& dig) {
		digitalWrite(dig.digitalRead());
		return *this;
	}

	Pwm& operator= (float value) {
		pwmWrite(value);
		return *this;
	}

	Pwm& operator= (Pwm& pwm) {
		pwm.pwmWrite(pwm.pwmWrite());
		return *this;
	}

	operator bool(){
		return digitalRead();
	}

	operator int() {
		return digitalRead();
	}

	operator float() {
		if (mode==MODE_PWM)return pwmWrite();
		else return 0.0;
	}
};

class Pwm4:public Digital,public Pwm{
private:
	enum{
		MODE_NULL,
		MODE_PWM,
		MODE_DIGITAL
	};
	int mode;
	int _digitalWrite();
	void _digitalWrite(int value);
	int _digitalRead();
	int _setupDigitalIn();
	int _setupDigitalOut();
	int _setupDigitalInPullUp();
	int _setupDigitalInPullDown();

	int _setupPwmOut(float frequency,float duty);
	void _pwmWrite(float duty);
	float _pwmWrite();
public:
	Pwm4(){mode=0;}

	Digital& operator= (int value) {
		digitalWrite(value);
		return *this;
	}

	Digital& operator= (Digital& dig) {
		digitalWrite(dig.digitalRead());
		return *this;
	}

	Pwm& operator= (float value) {
		pwmWrite(value);
		return *this;
	}

	Pwm& operator= (Pwm& pwm) {
		pwm.pwmWrite(pwm.pwmWrite());
		return *this;
	}

	operator bool(){
		return digitalRead();
	}

	operator int() {
		return digitalRead();
	}

	operator float() {
		if (mode==MODE_PWM)return pwmWrite();
		else return 0.0;
	}
};

class Pwm5:public Digital,public Pwm{
private:
	enum{
		MODE_NULL,
		MODE_PWM,
		MODE_DIGITAL
	};
	int mode;
	int _digitalWrite();
	void _digitalWrite(int value);
	int _digitalRead();
	int _setupDigitalIn();
	int _setupDigitalOut();
	int _setupDigitalInPullUp();
	int _setupDigitalInPullDown();

	int _setupPwmOut(float frequency,float duty);
	void _pwmWrite(float duty);
	float _pwmWrite();
public:
	Pwm5(){mode=0;}

	Digital& operator= (int value) {
		digitalWrite(value);
		return *this;
	}

	Digital& operator= (Digital& dig) {
		digitalWrite(dig.digitalRead());
		return *this;
	}

	Pwm& operator= (float value) {
		pwmWrite(value);
		return *this;
	}

	Pwm& operator= (Pwm& pwm) {
		pwm.pwmWrite(pwm.pwmWrite());
		return *this;
	}

	operator bool(){
		return digitalRead();
	}

	operator int() {
		return digitalRead();
	}

	operator float() {
		if (mode==MODE_PWM)return pwmWrite();
		else return 0.0;
	}
};

class Pwm6:public Digital,public Pwm{
private:
	enum{
		MODE_NULL,
		MODE_PWM,
		MODE_DIGITAL
	};
	int mode;
	int _digitalWrite();
	void _digitalWrite(int value);
	int _digitalRead();
	int _setupDigitalIn();
	int _setupDigitalOut();
	int _setupDigitalInPullUp();
	int _setupDigitalInPullDown();

	int _setupPwmOut(float frequency,float duty);
	void _pwmWrite(float duty);
	float _pwmWrite();
public:
	Pwm6(){mode=0;}

	Digital& operator= (int value) {
		digitalWrite(value);
		return *this;
	}

	Digital& operator= (Digital& dig) {
		digitalWrite(dig.digitalRead());
		return *this;
	}

	Pwm& operator= (float value) {
		pwmWrite(value);
		return *this;
	}

	Pwm& operator= (Pwm& pwm) {
		pwm.pwmWrite(pwm.pwmWrite());
		return *this;
	}

	operator bool(){
		return digitalRead();
	}

	operator int() {
		return digitalRead();
	}

	operator float() {
		if (mode==MODE_PWM)return pwmWrite();
		else return 0.0;
	}
};
class Pwm7:public Digital,public Pwm{
private:
	enum{
		MODE_NULL,
		MODE_PWM,
		MODE_DIGITAL
	};
	int mode;
	int _digitalWrite();
	void _digitalWrite(int value);
	int _digitalRead();
	int _setupDigitalIn();
	int _setupDigitalOut();
	int _setupDigitalInPullUp();
	int _setupDigitalInPullDown();

	int _setupPwmOut(float frequency,float duty);
	void _pwmWrite(float duty);
	float _pwmWrite();
public:
	Pwm7(){mode=0;}

	Digital& operator= (int value) {
		digitalWrite(value);
		return *this;
	}

	Digital& operator= (Digital& dig) {
		digitalWrite(dig.digitalRead());
		return *this;
	}

	Pwm& operator= (float value) {
		pwmWrite(value);
		return *this;
	}

	Pwm& operator= (Pwm& pwm) {
		pwm.pwmWrite(pwm.pwmWrite());
		return *this;
	}

	operator bool(){
		return digitalRead();
	}

	operator int() {
		return digitalRead();
	}

	operator float() {
		if (mode==MODE_PWM)return pwmWrite();
		else return 0.0;
	}
};

class Pwm8:public Digital,public Pwm{
private:
	enum{
		MODE_NULL,
		MODE_PWM,
		MODE_DIGITAL
	};
	int mode;
	int _digitalWrite();
	void _digitalWrite(int value);
	int _digitalRead();
	int _setupDigitalIn();
	int _setupDigitalOut();
	int _setupDigitalInPullUp();
	int _setupDigitalInPullDown();

	int _setupPwmOut(float frequency,float duty);
	void _pwmWrite(float duty);
	float _pwmWrite();
public:
	Pwm8(){mode=0;}

	Digital& operator= (int value) {
		digitalWrite(value);
		return *this;
	}

	Digital& operator= (Digital& dig) {
		digitalWrite(dig.digitalRead());
		return *this;
	}

	Pwm& operator= (float value) {
		pwmWrite(value);
		return *this;
	}

	Pwm& operator= (Pwm& pwm) {
		pwm.pwmWrite(pwm.pwmWrite());
		return *this;
	}

	operator bool(){
		return digitalRead();
	}

	operator int() {
		return digitalRead();
	}

	operator float() {
		if (mode==MODE_PWM)return pwmWrite();
		else return 0.0;
	}
};
class Pwm9:public Digital,public Pwm{
private:
	enum{
		MODE_NULL,
		MODE_PWM,
		MODE_DIGITAL
	};
	int mode;
	int _digitalWrite();
	void _digitalWrite(int value);
	int _digitalRead();
	int _setupDigitalIn();
	int _setupDigitalOut();
	int _setupDigitalInPullUp();
	int _setupDigitalInPullDown();

	int _setupPwmOut(float frequency,float duty);
	void _pwmWrite(float duty);
	float _pwmWrite();
public:
	Pwm9(){mode=0;}

	Digital& operator= (int value) {
		digitalWrite(value);
		return *this;
	}

	Digital& operator= (Digital& dig) {
		digitalWrite(dig.digitalRead());
		return *this;
	}

	Pwm& operator= (float value) {
		pwmWrite(value);
		return *this;
	}

	Pwm& operator= (Pwm& pwm) {
		pwm.pwmWrite(pwm.pwmWrite());
		return *this;
	}

	operator bool(){
		return digitalRead();
	}

	operator int() {
		return digitalRead();
	}

	operator float() {
		if (mode==MODE_PWM)return pwmWrite();
		else return 0.0;
	}
};

class Buzzer:public Digital,public Pwm{
private:
	enum{
		MODE_NULL,
		MODE_PWM,
		MODE_DIGITAL
	};
	int mode;
	int _digitalWrite();
	void _digitalWrite(int value);
	int _digitalRead();
	int _setupDigitalIn();
	int _setupDigitalOut();
	int _setupDigitalInPullUp();
	int _setupDigitalInPullDown();

	int _setupPwmOut(float frequency,float duty);
	void _pwmWrite(float duty);
	float _pwmWrite();
public:
	Buzzer(){mode=0;}

	Digital& operator= (int value) {
		digitalWrite(value);
		return *this;
	}

	Digital& operator= (Digital& dig) {
		digitalWrite(dig.digitalRead());
		return *this;
	}

	Pwm& operator= (float value) {
		pwmWrite(value);
		return *this;
	}

	Pwm& operator= (Pwm& pwm) {
		pwm.pwmWrite(pwm.pwmWrite());
		return *this;
	}

	operator bool(){
		return digitalRead();
	}

	operator int() {
		return digitalRead();
	}

	operator float() {
		if (mode==MODE_PWM)return pwmWrite();
		else return 0.0;
	}
};

//////////////////////////////
//////////////////////////////

class Enc0:public Encoder{
public:
	int setup();
	int count();

	operator int() {
		return count();
	}
};

class Enc1:public Encoder{
public:
	int setup();
	int count();

	operator int() {
		return count();
	}
};

class Enc2:public Encoder{
public:
	int setup();
	int count();

	operator int() {
		return count();
	}
};

class Enc3:public Encoder{
public:
	int setup();
	int count();

	operator int() {
		return count();
	}
};
//////////////////////////////


class Serial0:public Serial{
private:
	static SerialHandler *Handler;
	static RingBuffer<char,256> txBuf;
	static int isTransmitting;
	int _setup(int baudrate, SerialHandler &HandlerArg, int parity, int wordLength);
	friend int std_char_out_setup();
	friend void serial0_rxInterrupt();
	friend void serial0_txInterrupt();
	enum{
		SERIAL0_NEWLINE_NULL,
		SERIAL0_NEWLINE_LF,
		SERIAL0_NEWLINE_CR,
		SERIAL0_NEWLINE_CRLF
	};
	static int readNewLine;
	static int writeNewLine;
	static char oldWriteChar;
	static char oldReadChar;
public:
	static void transmit(char);
	void writeChar(char value);
	void setReadNewLineLF();
	void setReadNewLineCR();
	void setReadNewLineCRLF();
	void setWriteNewLineLF();
	void setWriteNewLineCR();
	void setWriteNewLineCRLF();
};

class Serial1:public Serial{
private:
	static SerialHandler *Handler;
	static RingBuffer<char,256> txBuf;
	static int isTransmitting;
	int _setup(int baudrate, SerialHandler &HandlerArg, int parity, int wordLength);
	//friend int std_char_out_setup();
	friend void serial1_rxInterrupt();
	friend void serial1_txInterrupt();
public:
	static void transmit(char);
	void writeChar(char value);
};

class Serial2:public Serial{
private:
	static SerialHandler *Handler;
	//static RingBuffer<char,256> txBuf;
	static RingBuffer<char,128> txBuf;
	static int isTransmitting;
	int _setup(int baudrate, SerialHandler &HandlerArg, int parity, int wordLength);
	//friend int std_char_out_setup();
	friend void serial2_rxInterrupt();
	friend void serial2_txInterrupt();
public:
	static void transmit(char);
	void writeChar(char value);
};

class Serial3:public Serial{
private:
	static SerialHandler *Handler;
	static RingBuffer<char,256> txBuf;
	static int isTransmitting;
	int _setup(int baudrate, SerialHandler &HandlerArg, int parity, int wordLength);
	//friend int std_char_out_setup();
	friend void serial3_rxInterrupt();
	friend void serial3_txInterrupt();
public:
	static void transmit(char);
	void writeChar(char value);
};

class Serial4:public Serial{
private:
	static SerialHandler *Handler;
	static RingBuffer<char,256> txBuf;
	static int isTransmitting;
	int _setup(int baudrate, SerialHandler &HandlerArg, int parity, int wordLength);
	//friend int std_char_out_setup();
	friend void serial4_rxInterrupt();
	friend void serial4_txInterrupt();
public:
	static void transmit(char);
	void writeChar(char value);
};

class Serial5:public Serial{
private:
	static SerialHandler *Handler;
	static RingBuffer<char,256> txBuf;
	static int isTransmitting;
	int _setup(int baudrate, SerialHandler &HandlerArg, int parity, int wordLength);
	//friend int std_char_out_setup();
	friend void serial5_rxInterrupt();
	friend void serial5_txInterrupt();
public:
	static void transmit(char);
	void writeChar(char value);
};

class WatchDog{
public:
	int setup();
	void cycle();
};

#include "can.hpp"
class CanTxMsger{
private:
	CanTxMsg canTxMsg[255];
	bool overFlag;
	int reader;
	int readerCount;
	int writer;
	int writerCount;
	int64_t timer;
	int64_t timeOutValue;
public:
	CanTxMsger(){overFlag=false;timer=0;reader=0;writer=0;readerCount=0;writerCount=0;timeOutValue=10;};
	int write(CanTxMsg data){
		if(readerCount+1==writerCount&&reader==writer+1){
			if(overFlag==false){
				overFlag=true;
				timer=millis();
			}
			if(millis()-timer<timeOutValue)
				return 1;
		}
		overFlag=false;
		canTxMsg[writer]=data;
		writer++;
		if(writer>=255){writer=0;writerCount++;}
		return 0;
	};
	CanTxMsg* read(){reader++;if(reader>=255){reader=0;readerCount++;}if(reader==0){return (canTxMsg+(254));}return (canTxMsg+(reader-1));
	};
	int txBufLength(){return ((writerCount*255+writer)-(readerCount*255+reader));};
	bool isEmpty(){if(txBufLength()==0)return true;else return false;};
	void timeOut(int time){timeOutValue=time;};
	int timeOut(){return timeOutValue;};
};


#define NUMBER_OF_CAN_Handler 100
class Can0:public Can{
public:
	static CanTxMsger canTxMs;
	static int isTransmitting;
	static	int64_t txTimer;
	Can0();
	int setup();
	int setupLoopBack();
	void setTxTimeOut(int time){canTxMs.timeOut(time);};
	int addHandler(CanHandler &HandlerArg);
	int setId(int id);
	int setIdAll();
	int write(int id,int number,unsigned char data[8]);
	int txBufLength(){return canTxMs.txBufLength();};
	int receiveErrorCounter();
	int transmitErrorCounter();
private:
	int filter_number;
	short filter[14*4];
	bool setuped;
	static CanHandler *canHandler[NUMBER_OF_CAN_Handler];
	static int canHandlerCursor;
	static int read(int id,int number,unsigned char data[8]);
	friend void Can0_rx_Interrupt();
	friend void Can0_tx_Interrupt();
};

class Can1:public Can{
public:
	static CanTxMsger canTxMs;
	static int isTransmitting;
	static int64_t txTimer;
	Can1();
	int setup();
	int setupLoopBack();
	void setTxTimeOut(int time){canTxMs.timeOut(time);};
	int addHandler(CanHandler &HandlerArg);
	int setId(int id);
	int setIdAll();
	int write(int id,int number,unsigned char data[8]);
	int txBufLength(){return canTxMs.txBufLength();};
private:
	int filter_number;
	short filter[14*4];
	bool setuped;
	static CanHandler *canHandler[NUMBER_OF_CAN_Handler];
	static int canHandlerCursor;
	static int read(int id,int number,unsigned char data[8]);
	friend void Can1_rx_Interrupt();
	friend void Can1_tx_Interrupt();
};

#include "../../layer_driver/base/timer_interrupt.hpp"
class TimerInterrupt0:public TimerInterrupt{
public:
	static TimerInterruptHandler* handler[5];
	static int count;
	//static RingBuffer<TimerInterruptHandler*,10> handler;
	TimerInterrupt0();
	int setup(float frequency);
	int addHandler(TimerInterruptHandler &handler);
	friend void TimerInterrupt0_timerCycle();
};

class DigitalInterrupt0{
public:
	DigitalInterrupt0();
	static bool handlerMap[16];
	static DigitalInterruptHandler* digitalInterruptHander[16];
	int digitalInterruptSetup(){return 0;};
};

#if 1
/***I2C****/
typedef struct{
	char data[20];
	char address;
	int dataSize;
	bool txrxFlag;
}I2c_t;

class I2c0:public I2c{
private:
	unsigned int time;
	static unsigned char sendData[20];
	static int i2cHandlerCursor;
	static RingBuffer<I2c_t,512> txBuf;
	static I2cHandler *i2cHandler[10];
	friend void I2c0_Interrupt();
	static void startI2c();
public:
	static bool directionFlag;
	static int txBufferSize;
	static int rxBufferSize;
	static int txSlaveAddress;
	static int rxSlaveAddress;
	I2c0();
	void cycle();
	int setup();
	int addHandler(I2cHandler &HandlerArg);
	int write(char address,unsigned char *value,char dataSize,bool txrx);


	bool direction(){return directionFlag;};
	void setRx(int rxBufferSize,int rxSlaveAddress);

	//���M�܂��͎�M�҂��t���O
	int getBufferFlag();
};

class Spi0:public Spi{
private:

	static SpiHandler *spiHandler[4];
	static SpiHandler *handler;
	static RingBuffer<unsigned char,100> txDataBuf;
	static RingBuffer<bool,10> optionDigital;
	static RingBuffer<SpiHandler*,20> handlerBuf;
	static bool transferFlag;
	static void getHandlerPointer();

	friend void Spi0_Interrupt();

	enum Status{

		SPI_START,
		SPI_CONNECTING,
		SPI_END,
	};
	static Status SpiStatus;

public:
	enum Mode{
		Mode0=0,
		Mode1,
		Mode2,
		Mode3,
			};
	static Mode mode;
	enum Direction{
		FullDuplex=0,
		TxOnly,
			};
	static Direction direction;
	Spi0(Mode mode,Direction direction);
	int setup();
	int optionPinSetup();
	int write(int byteSize,unsigned char data[8],SpiHandler *HandlerArg,bool optionPin=0);

	int addHandler(SpiHandler &HandlerArg);

};

#endif

#endif // __cplusplus
#endif // PIN_H_INCLUDED
