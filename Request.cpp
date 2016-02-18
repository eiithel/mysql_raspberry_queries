/*
 * File.cpp
 *
 *  Created on: 17 févr. 2016
 *      Author: ethel
 */

#include "Request.h"

Request::Request(){

}

Request::Request(const Request& f){

	polvector = f.polvector;

}

Request::~Request() {

}


void Request::append(Tabmodel* c){
	polvector.push_back(c);
}

void Request::writeToFile(){

	for(auto it = polvector.begin(); it!= polvector.end(); it++){
		(*it)->display();
		delete((*it));
	}

}


