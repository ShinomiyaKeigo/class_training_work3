#ifndef CAN_MAGNETIC_ENCODER
#define CAN_MAGNETIC_ENCODER
/*******************************************************************************************************************************************
 * can_magnetic_encoder ver1.0 2019/10/26
 * Class for using magnetic_encoder.
 * count is number of elements, default count is 4095.
 *
 * [Note]
 *
 * [Change history]
 * ver2.1  2019/ 12/ 11 Fix Bug by Shoma Nakaaki
 * ver2.0  2019/ 12/ 10 Changed to send data at specified intervals by Shoma Nakaaki
 * ver1.2  2019/ 11/  5 Fix Bug by Sato Yoshifumi
 * ver1.11 2019/ 11/  5 Add minor modification, make lighter process of cycle by Shinomiya Keigo
 * ver1.1  2019/ 11/  2 Add functions, cycle and mirror. Mirror is count down system from 4095 to 0   by Hayashi Istuki and Shinomiya Keigo
 * ver1.0  2019/ 10/ 26 First version. Add functions for magnetic_encoder   by Sato Yoshihumi, Uehara Yuta and Shinomiya Keigo
 *******************************************************************************************************************************************/
#include "layer_driver/board/pin.hpp"
#include "layer_driver/base/can.hpp"
#include "layer_driver/base/util.h"

#define CAN_MAGNETIC_ENCODER_ID 0x480

class CanMagneticEncoder : public CanHandler, public Encoder{
public:
    CanMagneticEncoder(Can &can, int number, int cpr = 4095);

    int setup();
    int setup(uint16_t send_time);
    void cycle();
    int count();
    int64_t timeStamp(){return micros();};

    void mirror(bool mirriorFlag);
    float degree();
    float radian();
    bool judge();

	int canRead(int id, int number, unsigned char data[8]);
	int canId(int id);

private:
	int id;
	int bit;
	float deg;
	float rad;
	bool mirrorFlag;
	bool flag;
};








#endif
