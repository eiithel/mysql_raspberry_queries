/*
 * club.h
 *
 *  Created on: 17 févr. 2016
 *      Author: ethel
 */
#include "Tabmodel.h"

#ifndef CLUB_H_
#define CLUB_H_

class club : public Tabmodel {
public:

	typedef struct club_t {
		int id;
		std::string name;
	}club_t ;

	club(club_t data ={ 1 ,"default" });

	club(int id, std::string name);

	virtual ~club();

	void display()const;

	friend std::ofstream& operator<<(std::ofstream& ofs, const club_t& c);

	static std::ofstream& fileclub;



private:
	club_t mdata;

};



#endif /* CLUB_H_ */
