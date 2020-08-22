#ifndef ADVANCED_LED_HPP
#define ADVANCED_LED_HPP
#include "layer_driver/base/digital.hpp"
#include "../layer_application/console.hpp"


#define MAX_DUTY	1

class AdvancedLed:public ConsoleCommand{
public:
	AdvancedLed(Digital *led, char *name);
	int setup();
	char* iam(){return name;};

	void pwm(float value);
	float pwm(void);

	//ConsoleCommand
	int commandCompare(char *command);
	int commandRequest(int argc,char **argv);


private:
	Digital *led;

	char name[10];
};

#endif//ADVANCED_ENCODER_HPP
