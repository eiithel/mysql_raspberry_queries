/*
 * Pet.cpp
 *
 *  Created on: 17 févr. 2016
 *      Author: ethel
 */

#include "Pet.h"


Pet::Pet(string n, string o, string sp,\
		string sex, string b, string d){
	mdata.name = n;
	mdata.owner = o;
	mdata.species = sp;
	mdata.sex = sex;
	mdata.birth = b;
	mdata.death = d;
}

Pet::Pet(pet_t data){
	mdata = data;
}

Pet::~Pet() {}

static std::ofstream outp("./sources/pet.txt", std::ios::app);
std::ofstream& Pet::filepet = outp;

void Pet::clean_s(){

	filepet.close();
	filepet.open("./sources/pet.txt", std::fstream::out | std::fstream::trunc);
	filepet.close();
	filepet.open("./sources/pet.txt", std::ios::app);
}

void Pet::clean(){
	Pet::clean_s();
}




void Pet::display()const{

	Pet::filepet << this->mdata;
}


std::ofstream& operator<<(std::ofstream& ofs, const Pet::pet_t& c){
	ofs << c.name << "\t"<< c.owner <<"\t"<< c.species <<"\t"\
			<< c.sex <<"\t"<< c.birth <<"\t"<< c.death <<"\n";

	return ofs;
}
