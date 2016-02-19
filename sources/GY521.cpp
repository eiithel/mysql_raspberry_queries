/*
 * GY521.cpp
 *
 *  Created on: 19 févr. 2016
 *      Author: ethel
 */

#include "GY521.h"

GY521::GY521(): _fd(0) {
	// TODO Auto-generated constructor stub

}

GY521::~GY521() {
	// TODO Auto-generated destructor stub
}

int GY521::init(){
	return wiringPiSetup();
}

void GY521::initI2C(int address){

	_fd = wiringPiI2CSetup(address);

	if(_fd==-1){
		printf("can't connect to the spi device %d", address);
	}

}

int GY521::readData(){
	return wiringPiI2CRead(_fd);

}

