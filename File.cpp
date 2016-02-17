/*
 * File.cpp
 *
 *  Created on: 17 févr. 2016
 *      Author: ethel
 */

#include "File.h"

File::File(const char* f):mfilename(f),mptr(NULL){

	myfile2.open ("example.txt", std::ios::app);

	if (myfile2.fail())
	{
		std::cerr <<"Can't open " << mfilename << std::endl;
		exit(1);
	}

}

File::~File() {

}


void File::writetest(){

	int size =3;

	club_t test[size]={
			{1,"AUS"},
			{2, "Gabi"},
			{3,"ethelou"},
	};

	mptr = test;

	for(int i=0;i<size;i++){
		myfile2 << test[i];
		mptr++;
	}

}


void File::appendVector(Tabmodel* c){
	polvector.push_back(c);
}

void File::writeFromvect(){

	for(auto it = polvector.begin(); it!= polvector.end(); it++){
		(*it)->display(myfile2);
		delete((*it));
	}

}


std::ofstream& operator<<(std::ofstream& ofs, const File::club_t& c){
	ofs << c.id << "\t" << c.name << "\n";
	return ofs;
}


