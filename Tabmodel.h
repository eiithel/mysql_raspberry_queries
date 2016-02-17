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



class Tabmodel {
public:


	Tabmodel();
	virtual ~Tabmodel();


	virtual void display(std::ofstream& ofs)const = 0;

	//	friend std::ofstream& operator<<(std::ofstream& ofs, const Tabmodel& c);//in order to write a sql formatted file




};

#endif /* TABMODEL_H_ */
