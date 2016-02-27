/*
 * File.cpp
 *
 *  Created on: 17 févr. 2016
 *      Author: ethel
 */

#include "File.h"

File::File(){
}

File::File(const File& f){

	_polvector = f._polvector;

}

File::~File() {

}


void File::append(Tabmodel* c){
	_polvector.push_back(c);
}

void File::writeToFile(){

	for(auto it = _polvector.begin(); it!= _polvector.end(); it++){
		(*it)->display();
		delete((*it));

	}
	_polvector.clear();

}


//void File::clean(char* filename){
//	std::ofstream myfile;
//	myfile.open(filename, ios::app);
//	myfile.close();
//	myfile.open(filename, std::fstream::out | std::fstream::trunc);
//	//myfile.open("filename", std::fstream::out | std::fstream::trunc);
//	myfile.close();
//
//}



