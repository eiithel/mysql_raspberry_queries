/*
 * i2cManager.cpp
 *
 *  Created on: 20 févr. 2016
 *      Author: ethel
 */

#include "i2cManager.h"
#include <string>

i2cManager::i2cManager():_slaveAddr(0x68), _fd(-1) {
	// TODO Auto-generated constructor stub

}

i2cManager::i2cManager(uint8_t slave): _slaveAddr(slave), _fd(-1){
}

i2cManager::~i2cManager() {
	// TODO Auto-generated destructor stub
}

void i2cManager::connectBus(){

	std::string filename = "/dev/i2c-1";

	if ((_fd = open(filename.c_str(), O_RDWR)) < 0) {
		perror("Failed to open the i2c bus");
		exit(1);
	}
	else{
		printf("\nconnected to i2c bus");
		printf("\n");
	}

}

void i2cManager::connectSlave(){

	if (ioctl(_fd,I2C_SLAVE, _slaveAddr) < 0) {
		printf("Failed to acquire bus access and/or talk to slave.\n");
		exit(1);
	}else{
		printf("\n talk to slave is ok");
	}

}

int i2cManager::getfd(){
	return _fd;
}

