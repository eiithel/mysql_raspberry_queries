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



class File {

public:

	File();
	File(const File& f);
	virtual ~File();

	void writeToFile();
	void append(Tabmodel* c);
	void clean(char* filename);

private:

	std::vector<Tabmodel*> _polvector;//pour faire polymorphisme

protected:


};

#endif /* FILE_H_ */
