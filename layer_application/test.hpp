#ifndef TEST_HPP
#define TEST_HPP
#include "layer_application/cycle_once.hpp"
#include "layer_driver/board/pin.hpp"

class Test{
public:
	Test(){
		led0.setupDigitalOut();
		led0.digitalLow();
	}
	void cycle(){
		if(!cycleOnce())return;
		led0.digitalToggle();
	}
	void cycleRestart(){cycleOnce.restart();}
private:
	CycleOnce cycleOnce;
	Led0 led0;
};

#endif //TEST_HPP
