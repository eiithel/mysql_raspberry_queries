/*
 * MPU6050table.cpp
 *
 *  Created on: 21 févr. 2016
 *      Author: ethel
 */

#include "MPU6050table.h"

MPU6050_table::MPU6050_table() {
	// TODO Auto-generated constructor stub

}

MPU6050_table::~MPU6050_table() {
	// TODO Auto-generated destructor stub
}

static std::ofstream outp("./sources/mpu.txt", std::ios::app);
std::ofstream& MPU6050_table::filempu = outp;

void MPU6050_table::clean_s(){

	filempu.close();
	filempu.open("./sources/mpu.txt", std::fstream::out | std::fstream::trunc);
	filempu.close();
	filempu.open("./sources/mpu.txt", std::ios::app);
}


void MPU6050_table::display()const{

	MPU6050_table::filempu << this->_mdata;
}


std::ofstream& operator<<(std::ofstream& ofs, const MPU6050_table::mpu_t& c){
	ofs << c.ax << "\t"<< c.ay <<"\t"<< c.az <<"\t"\
			<< c.date <<"\n";

	return ofs;
}

void MPU6050_table::getData(){

	_mpu.connect();
	usleep(25);
	_mpu.retrieveData();

	_mdata.ax = _mpu._realData.axg;
	_mdata.ay = _mpu._realData.ayg;
	_mdata.az = _mpu._realData.azg;
	_mdata.temp = _mpu._realData.temp;
	_mdata.date = _mpu._realData.date;

}
