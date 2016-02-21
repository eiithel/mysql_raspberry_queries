/*
 * MPU6050.cpp
 *
 *  Created on: 20 févr. 2016
 *      Author: ethel
 */

#include "MPU6050.h"

MPU6050::MPU6050(): _devAddr(0x68){
}

MPU6050::MPU6050(uint8_t address){
	_devAddr = address;

}

MPU6050::~MPU6050(){
}

void MPU6050::connect(){
	_con.connectBus();
	_con.connectSlave();
}


void MPU6050::getAx(){

	int file = _con.getfd();
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

void MPU6050::getAy(){

	int file = _con.getfd();
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

void MPU6050::getAz(){

	int file = _con.getfd();
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

void MPU6050::initialize(uint8_t accelRange){

	int file = _con.getfd();
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

void MPU6050::convertAccData(){

	_realData.axg = (float)(_rawData.x_accel-MPU6050_AXOFFSET)/MPU6050_AXGAIN;// divided by sensibility to have value in g.
	_realData.ayg = (float)(_rawData.y_accel-MPU6050_AYOFFSET)/MPU6050_AYGAIN;
	_realData.azg = (float)(_rawData.z_accel-MPU6050_AZOFFSET)/MPU6050_AZGAIN;

	printf("\ndata converties: ");
	printf("\n%f",_realData.axg);
	printf("\n%f",_realData.ayg);
	printf("\n%f",_realData.azg);
}

uint8_t MPU6050::getdevAddr(){
	return _devAddr;
}

MPU6050::raw_t MPU6050::getRawData(){
	return _rawData;
}

MPU6050::real_t MPU6050::getRealData(){
	return _realData;
}


float MPU6050::getTemp(){

	int file = _con.getfd();
	int8_t MSB, LSB;
	int16_t T;
	MSB = i2c_smbus_read_byte_data(file, MPU6050_RA_TEMP_OUT_H);
	LSB = i2c_smbus_read_byte_data(file, MPU6050_RA_TEMP_OUT_L);
	T = (((int16_t)MSB) << 8) | LSB;
	_rawData.temp = T;

	T = (float)T/325 + 35;
	_realData.temp = T;

	return T;

}
/*
 * tests gave:
 *  tempraw: -4864
	temp contains the value: 20.033846
 *	ok
 *
 *
 */

void MPU6050::retrieveData(){
	//todo faire une macro avec option debug pour pas afficher message de log à chaque fois.
	this->getAx();
	this->getAy();
	this->getAz();
	this->convertAccData();
	this->getTemp();
}

std::string MPU6050::getDate(){
	std::ostringstream stream;
	time_t rawtime;
	tm * timeinfo;

	time(&rawtime);
	timeinfo = localtime(&rawtime);

	stream << timeinfo->tm_hour <<"h "<<timeinfo->tm_min<<"mn "<<timeinfo->tm_sec <<"s";
	_realData.date = stream.str();
	return _realData.date;
}



