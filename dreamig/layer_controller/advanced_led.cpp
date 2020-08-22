#include "advanced_led.hpp"
#include "layer_driver/base/mcutime.h"
#include "layer_driver/base/util.hpp"
#include <stdlib.h>
#include <string.h>

AdvancedLed::AdvancedLed(Digital *led, char *name){
	this->led = led;

	strcpy(this->name, name);
}

int AdvancedLed::setup(){
	int error = led->setupDigitalOut();
	return error;
}

int AdvancedLed::commandCompare(char *command){
	return !(strcmp(name,command));
};

int AdvancedLed::commandRequest(int argc,char **argv){
	if(!strcmp(argv[1],"out")){
		if(argc == 3){
			led->digitalWrite((atoi(argv[2])));
			consolePrintf((char*)"set led->%d\r\n",atoi(argv[2]));
		}
	}else{
		consolePrintf((char*)"command error\r\n");
	}
	return 0;
};

