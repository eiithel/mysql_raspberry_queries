/*
 * Connect.h
 *
 *  Created on: 18 févr. 2016
 *      Author: ethel
 */

#ifndef CONNECT_H_
#define CONNECT_H_

#include <mysql/mysql.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;


class Connect {
public:
	Connect(string usr="pi", string mp="123", string db="menagerie");

	virtual ~Connect();
	void openConnexion();
	void close();
	MYSQL _mysql;

private:

	string _usr, _mp, _db;


};


#endif /* CONNECT_H_ */
