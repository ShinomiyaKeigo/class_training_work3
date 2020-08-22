#ifndef R1350NPLUS_HPP
#define R1350NPLUS_HPP
/*******************************************
 * can_encoderplus ver0.1 2015/3/5
 * Classes of can encoder node for ichigo system.
 *
 * [Dependency]
 * serial
 * util
 * math
 *
 * [Note]
 *
 * [Change history]
 * ver1.1 2019/10/24 improve rev function
 * ver1.1 2019/10/ 8 add reverse function for angleZ
 * ver1.0 2016/ 5/ 9 Some bug fix.
 * ver0.1 2015/ 3/ 5 The first version.Test.
 ******************************************/
#include "serial.hpp"
#include <math.h>
#include "mcutime.h"
#include "../base/util.h"
#include "layer_driver/base/angle_sensor.hpp"

class R1350n:public SerialHandler,public AngleSensor{
private:
	int angleData;
	int rateData;
	int accelXData;
	int accelYData;
	int accelZData;
	int initialAngleData;
	char readingData[15];
	int readingCount;
	int readStart;
	int angleRoopCount;
	int initialSetStart;
	float fangle;
	int oldAngleData;
	int timeData;
	int numberData;
	float value;
	bool over(int value){return value>9000;};
	bool under(int value){return value<-9000;};
	bool angleZRevFlag;

public:
	R1350n(Serial &serial){value=0;angleData=0;readingCount=0;readStart=0;initialSetStart=0;angleRoopCount=0;this->serial=&serial;initialAngleData=0;numberData=0;angleZRevFlag=false;};
	void serialReadChar(char data);

	int setup(){initialSetStart=1;return serial->setup(115200,(*this));};
	void cycle();
	//float angle();
	//int64_t timestamp(){return 0;};
	float rate(){return rateData*M_PI/18000.0;};
	float accelx(){return accelXData;};
	float accely(){return accelYData;};
	float accelz(){return accelZData;};
	int64_t time(){return timeData;};
	int number(){return numberData;};
	void reset(){initialAngleData=angleData;angleRoopCount=0;initialSetStart=1;numberData=0;};

	void angleZRev(bool rev){angleZRevFlag = rev;}
	bool angleZRev(){return angleZRevFlag;}
};

#endif//R1350NPLUS_HPP
