/*
 * club.cpp
 *
 *  Created on: 17 févr. 2016
 *      Author: ethel
 */

#include "club.h"

club::club(club_t data, char* f){
	_mdata = data;
	_filename =f;

	_fileclub=new std::ofstream;
	_fileclub->open(_filename,std::ios_base::app);

	if (_fileclub->fail())
	{
		std::cerr <<"Can't open " << _fileclub << std::endl;
		exit(1);
	}

}

club::club(int id, std::string name, char* f){
	_mdata.id = id;
	_mdata.name = name;
	_filename =f;

	_fileclub=new std::ofstream;
	_fileclub->open(_filename,std::ios_base::app);

	if (_fileclub->fail())
	{
		std::cerr <<"Can't open " << _fileclub << std::endl;
		exit(1);
	}

}

club::~club() {
	// TODO Auto-generated destructor stub
}


void club::clean_s(){

	_fileclub->close();
	_fileclub->open("./sources/club.txt", std::fstream::out | std::fstream::trunc);
	_fileclub->close();
}


void club::display()const{

	if(!_fileclub->is_open()){
		_fileclub->open(_filename,std::ios_base::app);
	}

	if (_fileclub!=NULL){
		*(_fileclub) << this->_mdata;
	}
	_fileclub->close();
}

std::ofstream& operator<<(std::ofstream& ofs, const club::club_t& c){
	ofs << c.id << "\t"<< c.name <<"\n";

	return ofs;
}


