#include "r1350n.hpp"
//#include "logging.h"
#include <stdio.h>

#define ON 1
#define OFF 0

/*
float R1350n::angle(){
	return -fangle;
}*/

void R1350n::serialReadChar(char data){
	readingData[readingCount] = data;

	if(readingData[0] == 0xAA){
		readStart = ON;
	}

	if(readStart == ON){
		readingCount++;
		if(readingCount >= 15){
			readingCount = 0;
			readStart = OFF;

			int ang_temp=(readingData[3] & 0xFF) | ((readingData[4] << 8) & 0xFF00);
			if(ang_temp<32768) angleData=-ang_temp;
			else angleData=-ang_temp+65536;

			int rate_temp=(readingData[5] & 0xFF) | ((readingData[6] << 8) & 0xFF00);
			if(rate_temp<32768) rateData=-rate_temp;
			else rateData=-rate_temp+65536;

			int accelx_temp=(readingData[7] & 0xFF) | ((readingData[8] << 8) & 0xFF00);
			if(accelx_temp<32768) accelXData=-accelx_temp;
			else accelXData=-accelx_temp+65536;

			int accely_temp=(readingData[9] & 0xFF) | ((readingData[10] << 10) & 0xFF00);
			if(accely_temp<32768) accelYData=-accely_temp;
			else accelYData=-accely_temp+65536;

			int accelz_temp=(readingData[11] & 0xFF) | ((readingData[12] << 10) & 0xFF00);
			if(accelz_temp<32768) accelZData=-accelz_temp;
			else accelZData=-accelz_temp+65536;

			if(initialSetStart){
				initialAngleData=angleData;
				initialSetStart=0;
				oldAngleData=angleData;
			}else{
				if(over(angleData)&&under(oldAngleData)){
					angleRoopCount--;
				}else if(over(oldAngleData)&&under(angleData)){
					angleRoopCount++;
				}
				oldAngleData=angleData;
				fangle=(angleData-initialAngleData)*M_PI/18000.0;
				fangle+=angleRoopCount*2*M_PI;
				timeData=millis();
				numberData++;
			}

		}
	}
}

void R1350n::cycle(){
	if(angleZRevFlag){
		angleZ(-fangle);
	}
	else{
		angleZ(fangle);
	}
}
