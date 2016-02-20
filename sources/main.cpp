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

	mpu.initialize(file,3);
	mpu.getAx(file);


	/*
	float data;
	char buf[10] = {0};
	char channel;

	for(int i = 0; i<4; i++) {
		if (read(file,buf,2) != 2) {
			printf("Failed to read from the i2c bus.\n");
			printf("\n\n");
		} else {
			data = (float)((buf[0] & 0b00001111)<<8)+buf[1];
			data = data/4096*5;
			channel = ((buf[0] & 0b00110000)>>4);
			printf("Channel %02d Data:  %04f\n",channel,data);
		}
	}

	 */

	return 0;

}


