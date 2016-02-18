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

	polvector = f.polvector;

}


File::~File() {

}


void File::appendVector(Tabmodel* c){
	polvector.push_back(c);
}

void File::writeFromvect(){

	for(auto it = polvector.begin(); it!= polvector.end(); it++){
		(*it)->display();
		delete((*it));
	}

}


