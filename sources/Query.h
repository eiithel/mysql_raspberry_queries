/*
 * Query.h
 *
 *  Created on: 18 févr. 2016
 *      Author: ethel
 */

#ifndef QUERY_H_
#define QUERY_H_

#include "Connect.h"
#include <string>

//#define LOAD "LOAD DATA LOCAL INFILE"

typedef enum
{
	PET,
	CLUB,

} Table;

typedef enum
{
	LOAD,
	INSERT,

}Type;


class Query {
public:
	Query();
	Query(Connect con, Table table, Type type);
	virtual ~Query();

	void send();

private:
	std::string getTable();// return a string which defines the appropriate table
	// and modify _file

	void setTable(Table tab);
	void setType(Type type);
	void updatefile();//update default file

	Connect _con;//A query corresponds to a specific connexion.
	Table _table;
	Type _type;
	std::string _file;
};

#endif /* QUERY_H_ */
