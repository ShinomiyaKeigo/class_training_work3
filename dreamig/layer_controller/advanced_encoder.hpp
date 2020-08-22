#ifndef ADVANCED_ENCODER_HPP
#define ADVANCED_ENCODER_HPP 2.1
/****************************************************************************************************************************
 * advanced_encoder ver2.1 2020/01/30
 * Class for expand encoders.
 *
 * [Note]
 * when you use this class with magnetic_encoder, please set absoluteFlag and firstCount.
 *
 * [Change history]
 * ver2.1 2020/01/30 add static_assert, add cycleOnceClass into member
 * ver2.0 2020/01/30 refactoring by Yuta Uehara
 * ver1.2 2020/01/30 delete comment out line by Yuta Uehara
 * ver1.1 2019/10/29 I'm sorry, repair bugs. this is available version.  by Shinomiya Keigo
 * ver1.0 2019/10/26 first version. add functions for magnetic_encoder   by Sato Yoshihumi, Uehara Yuta and Shinomiya Keigo.
 ***************************************************************************************************************************/
#include <math.h>
#include "layer_driver/base/encoder.hpp"
#include "layer_application/cycle_once.hpp"

class AdvancedEncoder:public Encoder{
public:
	int jumpData=0;

	AdvancedEncoder(Encoder &enc,int cpr,bool absoluteFlag = false, int firstCount=0):enc(enc),absoluteFlag(absoluteFlag),countData(firstCount){
		cprData = cpr;
		enc.rev(false);
		mltData = enc.mlt();
	};
	int setup()override;
	void cycle();
	void cycleRestart(){cycleOnce.restart();}
	int count()override;
	int getOldCount(){return oldCount;};
	float value()override;

	float revolution();
	float radian();
	float rps();
	float rps2();

	float rads();
	float rads2();
	int64_t timeStamp()override{return enc.timeStamp();}

	void setLimitVel(float value){limitVelValue=value;};
private:
	CycleOnce cycleOnce;

	Encoder &enc;

	int64_t time=0;
	int64_t lastCycleMicros=0;
	int64_t lastCountChangeMicros=0;
	int oldCount=0;
	float oldVelocity=0;

	int64_t cycleDeadTime=20000;
	int64_t velDeadTime=50000;
	float limitVelValue=800.0f/3.0f*M_PI;

	int countData=0;
	float rpsData=0;
	float rps2Data=0;

	bool absoluteFlag;
};

#endif//ADVANCED_ENCODER_HPP
