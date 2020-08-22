//libraries
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>
#include <typeinfo>
#include "library/library_ue.hpp"

//application
#include "layer_application/cycle_checker.hpp"
#include "layer_application/execute_function.hpp"
#include "layer_application/timer.hpp"
#include "layer_application/test.hpp"
//controller
#include "layer_controller/advanced_encoder.hpp"
#include "layer_controller/dc_motor_controller.hpp"
#include "layer_controller/motor_controller.hpp"
#include "layer_controller/bezier.hpp"
//base
#include "layer_driver/base/system.h"
#include "layer_driver/base/mcutime.h"
#include "layer_driver/base/angle_sensor.hpp"
#include "layer_driver/base/util.h"
#include "layer_driver/base/i2c.hpp"
#include "layer_driver/base/serial.hpp"
#include "layer_driver/base/pwm.hpp"
#include "layer_driver/base/digital.hpp"
#include "layer_driver/base/can.hpp"
#include "layer_driver/base/encoder.hpp"
//board
#include "pin.hpp"
//circuit
#include "layer_driver/circuit/can_digital.hpp"
#include "layer_driver/circuit/can_encoder.hpp"
#include "layer_driver/circuit/can_valve.hpp"
#include "layer_driver/circuit/dual_shock.hpp"
#include "layer_driver/circuit/led.hpp"
#include "layer_driver/circuit/motor_driver.hpp"
#include "layer_driver/circuit/can_motor_driver.hpp"
#include "layer_driver/circuit/r1350n.hpp"
#include "layer_driver/circuit/valve.hpp"
#include "layer_driver/circuit/sbdbt.hpp"
#include "layer_driver/circuit/jetson.hpp"
#include "layer_driver/circuit/can_vl53l0x.hpp"
#include "layer_driver/circuit/can_pwm.hpp"
#include "layer_driver/circuit/can_analog.hpp"
#include "layer_driver/circuit/can_voltage.hpp"
#include "layer_driver/circuit/can_magnetic_encoder.hpp"
#include "layer_driver/circuit/magnetic_magnetic_encoder.hpp"
#include "layer_driver/circuit/magnetic_potentio.hpp"
#include "layer_driver/circuit/can_vl53l0x.hpp"
#include "layer_driver/circuit/can_check.hpp"
#include "layer_driver/circuit/emergency.hpp"

#include "core_cm4.h"

int main(){

	//serial

	EmergencySwitch e_switch;	//緊急停止かける用のピン(常時high levelで緊急働かない,Low Levelになると緊急掛かる,つまり,digitalOut).
	EmergencyRead	e_read;		//緊急停止かかっているかどうかの読む用のピン(掛かっていない場合：Low Level,つまり,digitalRead)
	Emergency emergency(e_switch, e_read);	//緊急停止関連のオブジェクトの宣言.
	emergency.setup();	//緊急停止スイッチ押すのと同じ感覚

	Serial0 serial0;
	Serial1 serial1;
	Serial2 serial2;
	Serial3 serial3;
	Serial4 serial4;
	Serial5 serial5;

	Led0 led0;led0.setupDigitalOut();
	Led1 led1;led1.setupDigitalOut();
	Led2 led2;led2.setupDigitalOut();
	Led3 led3;led3.setupDigitalOut();
	Led4 led4;led4.setupDigitalOut();
	Led5 led5;led5.setupDigitalOut();

	Red red;red.setupDigitalOut();
	Blue blue;blue.setupDigitalOut();
	Green green;green.setupDigitalOut();

	ResetLed resetLed;resetLed.setupDigitalOut();

	Sw0 sw0;sw0.setupDigitalIn();
	Sw1 sw1;sw1.setupDigitalIn();
	Sw2 sw2;sw2.setupDigitalIn();
	Sw3 sw3;sw3.setupDigitalIn();

	Can0 can0;can0.setup();
	Can1 can1;can1.setup();

	Buzzer buzzer;buzzer.setupPwmOut(1000.f,0.f);

	D0 d0;
	D1 d1;
	D2 d2;
	D3 d3;

	A0 a0;
	A1 a1;
	A2 a2;
	A3 a3;
	A4 a4;
	A5 a5;
	A6 a6;
	A7 a7;
	A8 a8;


	SecondBezier bzr2;
	bzr2.setup();
	std::vector<std::vector<float> > xy2Points ={
			{0,0},
			{1000, 1000},
			{2000, 0}
	};
	bzr2.setPoints(xy2Points);
	bzr2.setPrametric(1000);
	bzr2.calculate();
	std::vector<float>xt = bzr2.getXt();
	std::vector<float>yt = bzr2.getYt();
	for (int t = 0; t <= 1000; ++t) {
		printf("%5.2f  %5.2f\n", xt[t], yt[t]);
	}

	CanDigital canDigital00(can0, 0);canDigital00.setup();
	CanDigital canDigital10(can1, 0);canDigital10.setup();

	Enc0 enc0;enc0.setup();
	Enc1 enc1;
	Enc2 enc2;
	Enc3 enc3;

	CycleChecker cycleChecker(2);

	ExecuteFunction exeFunc("fc");

	Console cons(serial0);
	cons.setup(9600);
	cons.setNewLine(Console::NEWLINE_CRLF);
	cons.addCommand(exeFunc);

	//executeFunction
	exeFunc.addFunc("reset",[&]{NVIC_SystemReset();});

	/******************** main ********************/

	//mainでの宣言
	Timer dispClock;dispClock(100,true);
	Timer ctrlClock;ctrlClock(2,true);

	lib_ue::Change<float> change(false);
	lib_ue::UpEdge up(false);
	lib_ue::DownEdge down(false);

	int64_t start_time = 0;

	while(!dispClock());

	while(1){
		//メインループ
		if(ctrlClock()){

		}

		//console
		if(dispClock()){
			cons.cycle();
			//			red.digitalToggle();
			blue.digitalToggle();
			//			green.digitalToggle();
			if(cycleChecker()){
				printf("cycle was delayed : %lld[ms]",cycleChecker.getMaxDelay());
				cycleChecker.reset();
			}
		}
	}//while括弧
	return 0;
}//main括弧


