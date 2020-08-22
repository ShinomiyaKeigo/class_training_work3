#ifndef LED_H_INCLUDED
#define LED_H_INCLUDED

class Led{
public:
	virtual int setup() = 0;
	virtual void cycle(){};

	virtual void on() = 0;
	virtual void off() = 0;
	virtual void toggle() = 0;
	virtual int read(){};
	virtual float pwm(){};
	virtual void pwm(float duty){};
};


#endif
