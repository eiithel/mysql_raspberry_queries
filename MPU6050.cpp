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
		PRINT_S("\nax contains the value: %d\n", ax);
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
		PRINT_S("\nay contains the value: %d\n", ay);
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
		PRINT_S("\naz contains the value: %d\n", az);
	}

}

void MPU6050::initialize(uint8_t accelRange){

	int file = _con.getfd();
	int8_t _aFSR  = accelRange << 3;
	usleep(25);// make sure sensor has time to power up

	//Sets sample rate to 8000/1+7 = 1000Hz
	i2c_smbus_write_byte_data(file, MPU6050_RA_SMPLRT_DIV, 0x07);
	//Disable FSync, 256Hz DLPF
	i2c_smbus_write_byte_data(file, MPU6050_RA_CONFIG, 0x00);
	//Disable gyro self tests, scale of 500 degrees/s
	i2c_smbus_write_byte_data(file, MPU6050_RA_GYRO_CONFIG, 0b00001000);
	//Disable accel self tests, scale of +-2g, no DHPF
	i2c_smbus_write_byte_data(file, MPU6050_RA_ACCEL_CONFIG, 0x00);
	//Freefall threshold of |0mg|
	i2c_smbus_write_byte_data(file, MPU6050_RA_FF_THR, 0x00);
	//Freefall duration limit of 0
	i2c_smbus_write_byte_data(file, MPU6050_RA_FF_DUR, 0x00);
	//Motion threshold of 0mg
	i2c_smbus_write_byte_data(file, MPU6050_RA_MOT_THR, 0x00);
	//Motion duration of 0s
	i2c_smbus_write_byte_data(file, MPU6050_RA_MOT_DUR, 0x00);
	//Zero motion threshold
	i2c_smbus_write_byte_data(file, MPU6050_RA_ZRMOT_THR, 0x00);
	//Zero motion duration threshold
	i2c_smbus_write_byte_data(file, MPU6050_RA_ZRMOT_DUR, 0x00);
	//Disable sensor output to FIFO buffer
	i2c_smbus_write_byte_data(file, MPU6050_RA_FIFO_EN, 0x00);

	//AUX I2C setup
	//Sets AUX I2C to single master control, plus other config
	i2c_smbus_write_byte_data(file, MPU6050_RA_I2C_MST_CTRL, 0x00);
	//Setup AUX I2C slaves
	i2c_smbus_write_byte_data(file, MPU6050_RA_I2C_SLV0_ADDR, 0x00);
	i2c_smbus_write_byte_data(file, MPU6050_RA_I2C_SLV0_REG, 0x00);
	i2c_smbus_write_byte_data(file, MPU6050_RA_I2C_SLV0_CTRL, 0x00);
	i2c_smbus_write_byte_data(file, MPU6050_RA_I2C_SLV1_ADDR, 0x00);
	i2c_smbus_write_byte_data(file, MPU6050_RA_I2C_SLV1_REG, 0x00);
	i2c_smbus_write_byte_data(file, MPU6050_RA_I2C_SLV1_CTRL, 0x00);
	i2c_smbus_write_byte_data(file, MPU6050_RA_I2C_SLV2_ADDR, 0x00);
	i2c_smbus_write_byte_data(file, MPU6050_RA_I2C_SLV2_REG, 0x00);
	i2c_smbus_write_byte_data(file, MPU6050_RA_I2C_SLV2_CTRL, 0x00);
	i2c_smbus_write_byte_data(file, MPU6050_RA_I2C_SLV3_ADDR, 0x00);
	i2c_smbus_write_byte_data(file, MPU6050_RA_I2C_SLV3_REG, 0x00);
	i2c_smbus_write_byte_data(file, MPU6050_RA_I2C_SLV3_CTRL, 0x00);
	i2c_smbus_write_byte_data(file, MPU6050_RA_I2C_SLV4_ADDR, 0x00);
	i2c_smbus_write_byte_data(file, MPU6050_RA_I2C_SLV4_REG, 0x00);
	i2c_smbus_write_byte_data(file, MPU6050_RA_I2C_SLV4_DO, 0x00);
	i2c_smbus_write_byte_data(file, MPU6050_RA_I2C_SLV4_CTRL, 0x00);
	i2c_smbus_write_byte_data(file, MPU6050_RA_I2C_SLV4_DI, 0x00);

	//MPU6050_RA_I2C_MST_STATUS //Read-only
	//Setup INT pin and AUX I2C pass through
	i2c_smbus_write_byte_data(file, MPU6050_RA_INT_PIN_CFG, 0x00);
	//Enable data ready interrupt
	i2c_smbus_write_byte_data(file, MPU6050_RA_INT_ENABLE, 0x00);

	//Slave out, dont care
	i2c_smbus_write_byte_data(file, MPU6050_RA_I2C_SLV0_DO, 0x00);
	i2c_smbus_write_byte_data(file, MPU6050_RA_I2C_SLV1_DO, 0x00);
	i2c_smbus_write_byte_data(file, MPU6050_RA_I2C_SLV2_DO, 0x00);
	i2c_smbus_write_byte_data(file, MPU6050_RA_I2C_SLV3_DO, 0x00);
	//More slave config
	i2c_smbus_write_byte_data(file, MPU6050_RA_I2C_MST_DELAY_CTRL, 0x00);
	//Reset sensor signal paths
	i2c_smbus_write_byte_data(file, MPU6050_RA_SIGNAL_PATH_RESET, 0x00);
	//Motion detection control
	i2c_smbus_write_byte_data(file, MPU6050_RA_MOT_DETECT_CTRL, 0x00);
	//Disables FIFO, AUX I2C, FIFO and I2C reset bits to 0
	i2c_smbus_write_byte_data(file, MPU6050_RA_USER_CTRL, 0x00);
	//Sets clock source to gyro reference w/ PLL  = for improved stability
	i2c_smbus_write_byte_data(file, MPU6050_RA_PWR_MGMT_1, 0b00000010);
	//Controls frequency of wakeups in accel low power mode plus the sensor standby modes
	i2c_smbus_write_byte_data(file, MPU6050_RA_PWR_MGMT_2, 0x00);

	i2c_smbus_write_byte_data(file, MPU6050_RA_FIFO_R_W, 0x00);

	i2c_smbus_write_byte_data(file,28,_aFSR);
	i2c_smbus_write_byte_data(file, 31, 0b00000000);		//  no motion detect
	i2c_smbus_write_byte_data(file, 35, 0b00000000);		//  no FIFO
	i2c_smbus_write_byte_data(file, 36, 0b00000000);		//  no mstr I2C
	i2c_smbus_write_byte_data(file, 55, 0b1110000);		//	configure interrupt  -- on when data ready, off on data read
	i2c_smbus_write_byte_data(file, 56, 0b00000001);		//	interrupt on
	i2c_smbus_write_byte_data(file, 106, 0b00000000);		//  no silly stuff
	i2c_smbus_write_byte_data(file, 107, 0b00000001);		//  no sleep and clock off gyro_X
	i2c_smbus_write_byte_data(file, 108, 0b00000000);

	PRINT_S("\nMPU6050 Setup Complete");

}

void MPU6050::convertAccData(){

	_realData.axg = (float)(_rawData.x_accel-MPU6050_AXOFFSET)/MPU6050_AXGAIN;// divided by sensibility to have value in g.
	_realData.ayg = (float)(_rawData.y_accel-MPU6050_AYOFFSET)/MPU6050_AYGAIN;
	_realData.azg = (float)(_rawData.z_accel-MPU6050_AZOFFSET)/MPU6050_AZGAIN;



	PRINT_S("\ndata converties: ");
	PRINT_S("\n%f",_realData.axg);
	PRINT_S("\n%f",_realData.ayg);
	PRINT_S("\n%f",_realData.azg);
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



