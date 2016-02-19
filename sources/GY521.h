/*
 * GY521.h
 *
 *  Created on: 19 févr. 2016
 *      Author: ethel
 */

#ifndef SOURCES_GY521_H_
#define SOURCES_GY521_H_

#include <wiringPi.h>
#include <wiringPiI2C.h>
#include <stdio.h>

// I use a GY521 sensor because it is the one that I have.

class GY521 {

public:
	GY521();
	virtual ~GY521();

	int init();
	void initI2C(int address);
	int readData();

private:
	int _fd;
};

#endif /* SOURCES_GY521_H_ */
