#ifndef DC_MOTORDRIVER_HPP
#define DC_MOTORDRIVER_HPP
#define LIMIT 0.95f
#include "layer_driver/base/util.h"
#include "layer_driver/base/pwm.hpp"
#include "layer_driver/circuit/motor_driver.hpp"


class DCMotorDriver:public MotorDriver{
public:
    DCMotorDriver(Pwm *pwm0,Pwm *pwm1);
    int setup();
    void cycle();
    void outRev(bool flag);
    void outRev();
    void duty(float duty);
    float duty();
    void free();

private:
    Pwm *pwm0;
    Pwm *pwm1;
    float duty0,duty1;
    int order;

};

#endif
