/*
 * Tabmodel.h
 *
 *  Created on: 17 févr. 2016
 *      Author: ethel
 */

#ifndef TABMODEL_H_
#define TABMODEL_H_

#include <time.h>
#include <string>
#include <fstream>
#include <ostream>
#include <iostream>



class Tabmodel {
public:


	Tabmodel();
	virtual ~Tabmodel();


	virtual void display()const = 0;
	virtual void clean() = 0;


};

#endif /* TABMODEL_H_ */
