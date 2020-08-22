#ifndef TIMER_INTERRUPT_HPP
#define TIMER_INTERRUPT_HPP

class TimerInterruptHandler{
public:
	virtual void timerInterrupt()=0;
};

class TimerInterrupt{
public:
	virtual int setup(float frequency)=0;
	virtual int addHandler(TimerInterruptHandler &handler)=0;
};

#endif//TIMER_INTERRUPT_HPP
