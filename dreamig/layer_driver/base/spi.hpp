#ifndef SPI_HPP
#define SPI_HPP
#include "layer_driver/base/digital.hpp"

class Spi;
class SpiHandler{
public:
	int spiSetup();
	int spiOptionPinSetup();
	//int canWrite(int idArg,int numberArg,unsigned char dataArg[8]);
	//int spiSetCs(Digital *cs);
	int spiWrite(int byteSize,unsigned char data[8],bool optionPin=0);
	virtual int spiRead(int byteSize,unsigned char data[8])=0;
	int spiHandlerSetup(Spi *spi);
	Digital *cs;
	Digital *optionPin;
private:

	Spi *spi;


};

class Spi{
public:

	virtual int setup()=0;
	virtual int optionPinSetup()=0;
	//virtual int spiSetCs(Digital *cs)=0;
	//virtual int write(char address,unsigned char *value,char dataSize,bool txrx)=0;
	virtual int write(int byteSize,unsigned char data[8],SpiHandler *HandlerArg,bool optionPin=0)=0;
	virtual int addHandler(SpiHandler &handlerArg)=0;

	int addHandler(SpiHandler *handlerArg){return addHandler(*handlerArg);};
};

class SpiHandlerNull:public SpiHandler{
public:
	virtual void spiRead(unsigned char *data){};
	virtual void spiReStartSend(char data){};
};

#if 0
#include <stdio.h>
class SpiNull:public Spi{
public:
	bool printfAvailable;
	int setupReturnValue;
	int writeReturnValue;
	int addHandlerReturnValue;
	bool directionReturnValue;
	SpiNull(bool printfAvailable=true){
		this->printfAvailable=printfAvailable;
		writeReturnValue=0;
		addHandlerReturnValue=0;
		directionReturnValue=false;
		setupReturnValue=0;
	}

	virtual int setup(){
		if(printfAvailable)printf("I2c::setup\n");
		return setupReturnValue;
	}
	virtual int write(char address,unsigned char *value,char dataSize,bool txrx){
		return writeReturnValue;
	}
	virtual int addHandler(I2cHandler &handlerArg){
		return addHandlerReturnValue;
	}

	virtual void setRx(int rxBufferSize,int rxSlaveAddress){
	}
	virtual bool direction(){
		return directionReturnValue;
	}
};
#endif

#endif
