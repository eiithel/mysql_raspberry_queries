/*
 * Connect.cpp
 *
 *  Created on: 18 févr. 2016
 *      Author: ethel
 */

#include "Connect.h"


Connect::Connect(string usr, string mp, string db){
	_usr = usr;
	_mp = mp;
	_db = db;
}


Connect::~Connect() {
	// TODO Auto-generated destructor stub
}

void Connect::openConnexion(){

	if(mysql_init(&mysql)==NULL)
	{
		printf("\nFailed to initate MySQL connection");
		exit(1);
	}

	char enable_load_infile =1;

	if(mysql_options(&mysql,MYSQL_OPT_LOCAL_INFILE, (const char *)&(enable_load_infile))){
		printf( "Failed to write file to MySQL: Error: %s\n",mysql_error(&mysql));

	}

	if(!mysql_real_connect(&mysql,"localhost",_usr.c_str(),_mp.c_str(),_db.c_str(),0,NULL,0))
	{

		printf( "Failed to connect to MySQL: Error: %s\n",
				mysql_error(&mysql));

		exit(1);

	}

	printf("\nLogged on to database sucessfully");
}

void Connect::close(){

	mysql_close(&mysql);


}



