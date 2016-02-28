/*
 * i2cManager.h
 *
 *  Created on: 20 févr. 2016
 *      Author: ethel
 */

#ifndef I2CMANAGER_H_
#define I2CMANAGER_H_

#include <unistd.h>
#include <linux/i2c-dev.h>
#include <stdint.h>

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
