/*
 * File.h
 *
 *  Created on: 17 févr. 2016
 *      Author: ethel
 */

#ifndef FILE_H_
#define FILE_H_

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


class File {

public:
	File(const char * f);
	virtual ~File();

	typedef struct club_t {
		int id;
		std::string name;
	}club_t ;

	void writetest();
	void writeFromvect();
	void appendVector(Tabmodel* c);

	friend std::ofstream& operator<<(std::ofstream& ofs, const club_t& c);//in order to write a sql formatted file


private:

	std::string mfilename;
	club_t* mptr;
	std::ofstream myfile2;
	std::vector<Tabmodel*> polvector;//pour faire polymorphisme

protected:


};

#endif /* FILE_H_ */
