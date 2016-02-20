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

}

//void Request::clean(){
//
//	for(auto it = polvector.begin(); it!= polvector.end(); it++){
//		(*it)->clean();
//		delete((*it));
//	}
//}


