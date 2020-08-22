#include "spi.hpp"

int SpiHandler::spiHandlerSetup(Spi *spi){
	this->spi=spi;
	return 0;
}

int SpiHandler::spiSetup(){
	//this->cs = cs;
	return spi->setup();
}

int SpiHandler::spiOptionPinSetup(){

	return spi->optionPinSetup();
}
/*
int SpiHandler::spiSetCs(Digital *cs){

	return 0;
}
*/
/*
int SpiHandler::spiWrite(char address,unsigned char *value,char dataSize,bool txrx){
	return spi->write(address,value,dataSize,txrx);
}
*/
int SpiHandler::spiWrite(int byteSize,unsigned char data[8],bool optionPin){
	return spi->write(byteSize,data,this,optionPin);
}
