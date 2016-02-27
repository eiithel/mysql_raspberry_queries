/*
 * MPU6050table.cpp
 *
 *  Created on: 21 févr. 2016
 *      Author: ethel
 */

#include "MPU6050table.h"

MPU6050_table::MPU6050_table(char* f) {

	_filename =f;

	_filempu=new std::ofstream;
	_filempu->open(_filename,std::ios_base::app);

	if (_filempu->fail())
	{
		std::cerr <<"Can't open " << _filempu << std::endl;
		exit(1);
	}

}

MPU6050_table::~MPU6050_table() {
	// TODO Auto-generated destructor stub
}


void MPU6050_table::clean_s(){

	_filempu->close();
	_filempu->open("./sources/mpu.txt", std::fstream::out | std::fstream::trunc);
	_filempu->close();
}


void MPU6050_table::display()const{

	if(!_filempu->is_open()){
		_filempu->open(_filename,std::ios_base::app);
	}

	if (_filempu!=NULL){
		*(_filempu) << this->_mdata;
	}
	_filempu->close();

}


std::ofstream& operator<<(std::ofstream& ofs, const MPU6050_table::mpu_t& c){
	ofs << c.ax << "\t"<< c.ay <<"\t"<< c.az <<"\t"\
			<< c.date <<"\n";

	return ofs;
}



void MPU6050_table::getData(){
	//TODO test

	_mpu.connect();
	_mpu.initialize(0);
	usleep(25);
	_mpu.retrieveData();

	_mdata.ax = _mpu._realData.axg;
	_mdata.ay = _mpu._realData.ayg;
	_mdata.az = _mpu._realData.azg;
	_mdata.temp = _mpu._realData.temp;
	_mdata.date = _mpu._realData.date;

}

