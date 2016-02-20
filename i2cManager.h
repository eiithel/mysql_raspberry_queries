/*
 * i2cManager.h
 *
 *  Created on: 20 févr. 2016
 *      Author: ethel
 */
#include "MPU6050.h"


#ifndef I2CMANAGER_H_
#define I2CMANAGER_H_

class i2cManager {
public:
	i2cManager();
	i2cManager(uint8_t slave);
	virtual ~i2cManager();

	void connectBus();
	void connectSlave();

	int getfd();

private:
	uint8_t _slaveAddr;
	int _fd;

};

#endif /* I2CMANAGER_H_ */
