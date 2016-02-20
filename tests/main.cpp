#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <unistd.h>
#include "MPU6050.h"
#include "i2cManager.h"


int main(){

	printf("\nentree du programme");

	MPU6050 mpu(0x68);
	i2cManager i2c;

	i2c.connectBus();
	i2c.connectSlave();

	int file = i2c.getfd();

	mpu.initialize(file,0);//sensitivity settings = +-2g
	mpu.getAx(file);
	mpu.getAy(file);
	mpu.getAz(file);

	mpu.convertAccData();

	/*
The first test on the device gave me:

ax contains the value: 13360

ay contains the value: 9844

az contains the value: 3072

data converties:
0.815430
0.600830
0.187500

	 */

	return 0;

}


