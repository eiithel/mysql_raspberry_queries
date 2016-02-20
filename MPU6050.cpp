/*
 * MPU6050.cpp
 *
 *  Created on: 20 févr. 2016
 *      Author: ethel
 */

#include "MPU6050.h"

MPU6050::MPU6050(): _devAddr(0x68), _fd(0){
}

MPU6050::MPU6050(uint8_t address){
	_devAddr = address;
	_fd =0;

}

MPU6050::~MPU6050(){
}

void MPU6050::getAx(int file){

	int8_t MSB, LSB;
	int16_t ax;

	MSB = i2c_smbus_read_byte_data(file, MPU6050_RA_ACCEL_XOUT_H);
	LSB = i2c_smbus_read_byte_data(file, MPU6050_RA_ACCEL_XOUT_L);
	ax = (((int16_t)MSB) << 8) | LSB;
	_rawData.x_accel =ax;

	if (ax < 0){
		printf("\ni2c transaction failed.\n");
		exit(1);
	} else {
		printf("\nax contains the value: %d\n", ax);
	}

}

void MPU6050::getAy(int file){
	int8_t MSB, LSB;
	int16_t ay;

	MSB = i2c_smbus_read_byte_data(file, MPU6050_RA_ACCEL_YOUT_H);
	LSB = i2c_smbus_read_byte_data(file, MPU6050_RA_ACCEL_YOUT_L);
	ay = (((uint16_t)MSB) << 8) | LSB;
	_rawData.y_accel = ay;

	if (ay < 0){
		printf("\ni2c transaction failed.\n");
		exit(1);
	} else {
		printf("\nay contains the value: %d\n", ay);
	}
}

void MPU6050::getAz(int file){
	int8_t MSB, LSB;
	int16_t az;

	MSB = i2c_smbus_read_byte_data(file, MPU6050_RA_ACCEL_ZOUT_H);
	LSB = i2c_smbus_read_byte_data(file, MPU6050_RA_ACCEL_ZOUT_L);
	az = (((int16_t)MSB) << 8) | LSB;
	_rawData.z_accel = az;

	if (az < 0){
		printf("\ni2c transaction failed.\n");
		exit(1);
	} else {
		printf("\naz contains the value: %d\n", az);
	}

}

void MPU6050::initialize(int file,uint8_t accelRange){
	int8_t _aFSR  = accelRange << 3;
	usleep(25);// make sure sensor has time to power up

	i2c_smbus_write_byte_data(file,28,_aFSR);
	i2c_smbus_write_byte_data(file, 31, 0b00000000);		//  no motion detect
	i2c_smbus_write_byte_data(file, 35, 0b00000000);		//  no FIFO
	i2c_smbus_write_byte_data(file, 36, 0b00000000);		//  no mstr I2C
	i2c_smbus_write_byte_data(file, 55, 0b1110000);		//	configure interrupt  -- on when data ready, off on data read
	i2c_smbus_write_byte_data(file, 56, 0b00000001);		//	interrupt on
	i2c_smbus_write_byte_data(file, 106, 0b00000000);		//  no silly stuff
	i2c_smbus_write_byte_data(file, 107, 0b00000001);		//  no sleep and clock off gyro_X
	i2c_smbus_write_byte_data(file, 108, 0b00000000);

}

uint8_t MPU6050::getdevAddr(){
	return _devAddr;
}

MPU6050::mpu6050_raw MPU6050::getRawData(){
	return _rawData;
}



