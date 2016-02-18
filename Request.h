/*
 * File.h
 *
 *  Created on: 17 févr. 2016
 *      Author: ethel
 */

#ifndef REQUEST_H_
#define REQUEST_H_

#include <cstdio>
#include <string.h>
#include <fstream>
#include <iostream>
#include <ostream>
#include <stdlib.h>
#include <vector>

#include "Tabmodel.h"
#include "club.h"
#include "Pet.h"


class Request {

public:

	Request();
	Request(const Request& f);
	virtual ~Request();

	void writeToFile();
	void append(Tabmodel* c);

private:

	std::vector<Tabmodel*> polvector;//pour faire polymorphisme

protected:


};

#endif /* REQUEST_H_ */
