/*
 * rosserial.hpp
 *
 *  Created on: 2017/10/08
 *      Author: broom
 */

#ifndef ROSSERIAL_HPP_
#define ROSSERIAL_HPP_

#include "../layer_driver/board/pin.hpp"
#define SERIAL_CLASS Serial1
#define BAUD 77600

#include "../layer_driver/base/serial.hpp"

class Rosserial :public SerialHandler{
  public:
	//static SERIAL_CLASS serial;
	SERIAL_CLASS serial;

	Rosserial()
    {
	  //this->serialHandlerSetup(&serial);
	  serial.setup(BAUD);
      baud_ = BAUD;
    }

    void setBaud(long baud){
      this->baud_= baud;
    }

    int getBaud(){return baud_;}

    void init(){
      //serial.setup(baud_,(*this));
    }

    int read(){
    	if(!serial.charAvailable()) return -1;
    	return serial.readChar();
    };
    void write(uint8_t* data, int length){
     for(int i=0; i<length; i++)
        serial.writeChar(data[i]);
    }

    unsigned long time(){return millis();}

  protected:
    SERIAL_CLASS* iostream;
    long baud_;
};
#endif /* ROSSERIAL_HPP_ */
