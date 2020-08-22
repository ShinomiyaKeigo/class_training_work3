#include "layer_controller/advanced_encoder.hpp"
#include "mcutime.h"

static_assert(ADVANCED_ENCODER_HPP==2.1,"AdvancedEncoder version does not match. Check the latest version of the file on github.(AdvancedEncoderクラスのcppとhppのバージョンが一致しません。githubで最新バージョンのファイルを確認してください。)");

int AdvancedEncoder::setup(){
	lastCountChangeMicros=millis();
	return enc.setup();
}

void AdvancedEncoder::cycle(){
	if(!cycleOnce())return;

	int64_t cycleMicros=enc.timeStamp();
	int dtMicros=cycleMicros-lastCountChangeMicros;

	if(dtMicros<=0)return;

	int encCount=enc.count();
	//************************************************************************:

	int gap=encCount-oldCount;
	if(absoluteFlag){
		if((float)gap / cprData > 0.5f){//+180度以上回転する時			
			gap -= cprData;
		}
		else if((float)gap / cprData < -0.5f){// -180度以上回転するとき
			gap += cprData;
		}

	}

	oldCount=encCount;

	if(revFlag)gap*=-1;

	//Max permissible revolution of encoders of omron is 5000 r/min
	//If over the value, this is wrong value.
	if((fabs(gap)/cprData/dtMicros*1000000.0f*M_PI*2.0f>limitVelValue&&gap!=0 && !absoluteFlag) ||cycleMicros-lastCycleMicros>cycleDeadTime){//10000*cpr/60*(dtMicros/1000000)
		lastCycleMicros=cycleMicros;
		jumpData++;
		lastCountChangeMicros=cycleMicros;
		return;
	}
	lastCycleMicros=cycleMicros;
	countData+=gap;

	if(gap!=0){
		float temp=gap*1000000.0f/cprData/(float)dtMicros;
		rps2Data=(temp-rpsData)*1000000.0f/(float)dtMicros;
		rpsData=temp;//gap/(dtMicros/1000000)/cprData
	}
	if(cycleMicros-lastCountChangeMicros>velDeadTime){
		lastCountChangeMicros=cycleMicros;
		rps2Data=-rpsData;
		rpsData=0.0f;
	}

	if(gap!=0)lastCountChangeMicros=cycleMicros;
}

int AdvancedEncoder::count(){
	return countData;
}

float AdvancedEncoder::value(){
	return mltData*radian();
}


float AdvancedEncoder::revolution(){
	return (float)countData/cprData;
}

float AdvancedEncoder::radian(){
	return 2.0*M_PI*(float)countData/cprData;
}

float AdvancedEncoder::rps(){
	return rpsData;
}

float AdvancedEncoder::rps2(){
	return rps2Data;
}

float AdvancedEncoder::rads(){
	return rpsData*2*M_PI;
}

float AdvancedEncoder::rads2(){
	return rps2Data*2*M_PI;
}
