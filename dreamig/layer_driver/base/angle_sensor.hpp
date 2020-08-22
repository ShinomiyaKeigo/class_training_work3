#ifndef ANGLE_SENSOR_HPP
#define ANGLE_SENSOR_HPP
#include "util.hpp"
#include "mcutime.h"
#include "pin.hpp"

class AngleSensor:public Coord<float>{
public:
	virtual int setup()=0;
	virtual void cycle()=0;
};


#endif
