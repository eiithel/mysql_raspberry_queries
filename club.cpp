/*
 * club.cpp
 *
 *  Created on: 17 févr. 2016
 *      Author: ethel
 */

#include "club.h"

club::club(club_t data){
	mdata= data;
}

club::club(int id, std::string name){
	mdata.id = id;
	mdata.name = name;
}

club::~club() {
	// TODO Auto-generated destructor stub
}

void club::display(std::ofstream& ofs)const{
	ofs << this->mdata;
}

std::ofstream& operator<<(std::ofstream& ofs, const club::club_t& c){
	ofs << c.id << "\t"<< c.name <<"\n";

	return ofs;
}


