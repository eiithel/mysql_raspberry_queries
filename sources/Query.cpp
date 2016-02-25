/*
 * Query.cpp
 *
 *  Created on: 18 févr. 2016
 *      Author: ethel
 */

#include "Query.h"

Query::Query(): _table(PET), _type(INSERT), _file("'./sources/pet.txt'"){

}

Query::~Query() {
	// TODO Auto-generated destructor stub
}

Query::Query(Connect con, Table table, Type type): _con(con), _table(table),\
		_type(type)
		{
		}

void Query::setTable(Table tab){
	_table = tab;
}

void Query::setType(Type type){
	_type = type;
}

std::string Query::getTable(){
	std::string str;
	switch (_table) {
	case PET:
		str= "pet";
		_file = "'./sources/pet.txt'";

		break;
	case CLUB:
		str= "club";
		_file = "'./sources/club.txt'";

		break;
	case MPU:
		str= "MPU6050";
		_file = "'./sources/mpu.txt'";
		break;
	}
	return str;
}


void Query::send(){
	std::string squery, stable;
	MYSQL sql = _con._mysql;
	stable = getTable();

	if(_type == LOAD){
		ifstream n;
		n.open("./sources/mpu.txt");
		squery = "LOAD DATA LOCAL INFILE " + _file + "INTO TABLE " + stable;
	}

	if(_type == INSERT){
		squery = "INSERT INTO" + stable + "VALUES";
		//TODO finish this part : add values to insert
	}

	if(mysql_query(&sql, squery.c_str())){
		printf( "Failed to write to MySQL: Error: %s\n",  mysql_error(&sql));
	}else{
		printf( "\nwriting to table %s was sucessfull", stable.c_str());
		printf("\n");
	}

}


void Query::updatefile(){
	//TODO to implement
}

