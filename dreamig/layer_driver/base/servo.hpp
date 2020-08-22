#ifndef SERVO_HPP
#define SERVO_HPP

class Servo{
public:
  virtual int setup()=0;
  virtual void angle(float)=0;
  virtual float angle()=0;
  virtual void cycle()=0;
};

#endif // SERVO_HPP
