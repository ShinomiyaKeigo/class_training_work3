#ifndef MAGNETIC_POTENTIO_HPP
#define MAGNETIC_POTENTIO_HPP

#include "layer_driver/base/util.h"
#include "layer_driver/base/analog.hpp"
#include "layer_driver/circuit/can_magnetic_encoder.hpp"

#define POTENTIO_NUM 10
#define THRESHOLD 3800//後日要修正

class MagneticPotentio{
public:
	MagneticPotentio(Analog &potentio,CanMagneticEncoder &magneticEnc);
	int setup(int potentio_min,int potentio_max,int magnetic_enc_min,int range);
	void rev(bool potentio_rev,bool magnetic_enc_rev);
	void cycle();
	int magPoteCount();     //return Encoder count(0~4096*rotation_number)
	int magneticEncCount(); //return now multiTurnEncCount
	int potentioCount();//return now multiTurnEncCount

	int potentioMax(){return potentio_max;};
	int potentioMin(){return potentio_min;};

private:
	Analog *potentio;
	CanMagneticEncoder *magneticEnc;

	bool potentio_rev_flag;
	int count;
	int magnetic_enc_count;
	int potentio_count;
	int potentio_min;
	int potentio_max;
	int magnetic_enc_min;
	int step_range;//
	int potentio_val_memo[POTENTIO_NUM];
	int potentio_value;
	int potentio_sum;
};
#endif
