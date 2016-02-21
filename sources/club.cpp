/*
 * club.cpp
 *
 *  Created on: 17 févr. 2016
 *      Author: ethel
 */

#include "club.h"

club::club(club_t data){
	_mdata= data;
}

club::club(int id, std::string name){
	_mdata.id = id;
	_mdata.name = name;
}

club::~club() {
	// TODO Auto-generated destructor stub
}

static std::ofstream outc("./sources/club.txt", std::ios::app);
std::ofstream& club::fileclub = outc;

void club::clean_s(){

	fileclub.close();
	fileclub.open("./sources/club.txt", std::fstream::out | std::fstream::trunc);
	fileclub.close();
	fileclub.open("./sources/club.txt", std::ios::app);
}

//void club::clean(){
//	club::clean_s();
//}

void club::display()const{
	//	club::fileclub.open("club.txt",std::ios::app);

	club::fileclub << this->_mdata;
}

std::ofstream& operator<<(std::ofstream& ofs, const club::club_t& c){
	ofs << c.id << "\t"<< c.name <<"\n";

	return ofs;
}


