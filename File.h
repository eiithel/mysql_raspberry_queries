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

	File();
	File(const File& f);
	virtual ~File();

	void writeFromvect();
	void appendVector(Tabmodel* c);

private:

	std::vector<Tabmodel*> polvector;//pour faire polymorphisme

protected:


};

#endif /* FILE_H_ */
