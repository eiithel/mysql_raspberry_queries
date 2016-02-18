/*
 * Pet.h
 *
 *  Created on: 17 févr. 2016
 *      Author: ethel
 */

#ifndef PET_H_
#define PET_H_

#include "Tabmodel.h"

using namespace std;


class Pet : public Tabmodel{
public:

	typedef struct pet_t {

		string name;
		string	owner;
		string species;
		string sex;
		string birth;
		string death;

	}pet_t ;

	Pet(pet_t data ={"fanny","sarah","cochon","f","1995-05-10", ""});//par defaut

	Pet(string n, string o, string sp,\
			string sex, string b, string d);

	virtual ~Pet();

	void display()const;

	friend std::ofstream& operator<<(std::ofstream& ofs, const pet_t& c);

	static std::ofstream& filepet;


private:

	pet_t mdata;

};



#endif /* PET_H_ */
