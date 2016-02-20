#include <mysql/mysql.h>
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <unistd.h>
#include "Pet.h"
#include "club.h"
#include "Tabmodel.h"
#include "Connect.h"
#include "File.h"
#include "Query.h"
#include "../MPU6050.h"
#include "../i2cManager.h"



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
	float temp = mpu.getTemp(file);

	printf("\nla temperature est de: %f", temp);


	return 0;

}


