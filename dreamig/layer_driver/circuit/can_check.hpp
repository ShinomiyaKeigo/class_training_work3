#ifndef CAN_CHECK_HPP
#define CAN_CHECK_HPP

#include "layer_driver/base/can.hpp"
#include "mcutime.h"

/*--------------------------------
瑠璃(IO基板)専用
can通信確認用
--------------------------------*/



#define CAN_CHECK_ID 0x780


class CanCheck : CanHandler{
public:
	CanCheck(Can &can, int number);
	int setup();
	int check();

	int canRead(int id, int number, unsigned char data[8]);
	int canId(int id);
private:
	int id;
	bool flag;
	bool ck;
};


#endif
