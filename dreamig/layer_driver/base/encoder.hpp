#ifndef ENCODER_H_INCLUDED
#define ENCODER_H_INCLUDED
/*******************************************
 * encoder ver2.0 2015/10/8
 * Encoder class.
 *
 * [Dependency]
 *
 * [Note]
 *
 * [Change history]
 * ver2.1 2020/01/30 Protected the variables
 * ver2.0 2015/10/ 9 improve dependency.
 * ver1.0 2015/ 3/ 3 The first version.
 ******************************************/
#include "mcutime.h"
class Encoder{
protected:
	int cprData;
	bool revFlag;
	float mltData;
public:
	Encoder(){cprData=1;revFlag=false;mltData=1;};

	//depends on hardware
	virtual int setup()=0;
	virtual int count()=0;
	virtual int64_t timeStamp(){return micros();};
	virtual float value();

	void rev(bool value);
	void rev(){revFlag=!revFlag;};
	void mlt(float mltArg);
	float mlt();
	void cpr(int cprArg);
	int cpr();
	float radian();
};
#include <stdio.h>
class EncoderNull:public Encoder{//It seems to be a working check class.
								 //It is 2019/4/24 now, but it seems that it has not been used for four years.
public:
	bool printfAvailable;
	int countData;
	int setupReturnValue;
	EncoderNull(bool printfAvailable=true){cprData=1;revFlag=false;mltData=1;this->printfAvailable=printfAvailable;countData=0;setupReturnValue=0;};

	//depends on hardware
	virtual int setup(){
		if(printfAvailable)printf("EncoderNull::setup\n");
		return setupReturnValue;
	};
	virtual int count(){
		return countData;
	}
};

#endif // ENCODER_H_INCLUDED
