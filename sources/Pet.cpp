/*
 * Pet.cpp
 *
 *  Created on: 17 févr. 2016
 *      Author: ethel
 */

#include "Pet.h"


Pet::Pet(string n, string o, string sp,\
		string sex, string b, string d, char* f){
	_mdata.name = n;
	_mdata.owner = o;
	_mdata.species = sp;
	_mdata.sex = sex;
	_mdata.birth = b;
	_mdata.death = d;
	_filename =f;

	_filepet=new std::ofstream;
	_filepet->open(_filename,std::ios_base::app);

	if (_filepet->fail())
	{
		std::cerr <<"Can't open " << _filepet << std::endl;
		exit(1);
	}

}

Pet::Pet(pet_t data, char* f){
	_mdata = data;
	_filename =f;

	_filepet=new std::ofstream;
	_filepet->open(_filename,std::ios_base::app);

	if (_filepet->fail())
	{
		std::cerr <<"Can't open " << _filepet << std::endl;
		exit(1);
	}
}

Pet::~Pet() {
	delete(_filepet);
}


void Pet::clean_s(){


	if(_filepet->is_open()){
		_filepet->close();
	}

	if( remove( "./sources/pet.txt" ) != 0 )
		perror( "Error deleting file\n" );
	else
		printf("fichier supprime\n");


}



void Pet::display()const{
	if(!_filepet->is_open()){
		_filepet->open(_filename,std::ios_base::app);
	}

	if (_filepet!=NULL){
		*(_filepet) << this->_mdata;
	}
	_filepet->close();
}


std::ofstream& operator<<(std::ofstream& ofs, const Pet::pet_t& c){
	ofs << c.name << "\t"<< c.owner <<"\t"<< c.species <<"\t"\
			<< c.sex <<"\t"<< c.birth <<"\t"<< c.death <<"\n";

	return ofs;
}

