#include <mysql/mysql.h>
#include <stdio.h>
#include <stdlib.h>
#include "File.h"
#include "Pet.h"
#include "club.h"
#include "Tabmodel.h"


int main(){

	printf("\nentree du programme");

	Pet *p3 = new Pet;
	Pet *p4 = new Pet;

	club *c1 = new club;
	club *c2 = new club(2,"julien");

	File file("example.txt");

	file.appendVector(p3);
	file.appendVector(p4);
	file.appendVector(c1);
	file.appendVector(c2);

	file.writeFromvect();

	MYSQL mysql;

	if(mysql_init(&mysql)==NULL)
	{
		printf("\nFailed to initate MySQL connection");
		exit(1);
	}

	char enable_load_infile =1;

	if(mysql_options(&mysql,MYSQL_OPT_LOCAL_INFILE, (const char *)&(enable_load_infile))){
		printf( "Failed to write file to MySQL: Error: %s\n",mysql_error(&mysql));

	}


	if(!mysql_real_connect(&mysql,"localhost","pi","123","menagerie",0,NULL,0))
	{

		printf( "Failed to connect to MySQL: Error: %s\n",
				mysql_error(&mysql));

		exit(1);

	}

	printf("\nLogged on to database sucessfully");

	//	if(!mysql_query(&mysql, "INSERT INTO club VALUES( 3 ,'Topless')"))
	//	{ printf("gabi enregistre");//pour marcher avoir exact le bn nombre d'arg en param
	//	}

	//	if(mysql_query(&mysql, "LOAD DATA LOCAL INFILE '~/Documents/json_data/pet.txt' INTO table pet")){
	//		printf( "Failed to write to MySQL: Error: %s\n",  mysql_error(&mysql));
	//	}

	if(mysql_query(&mysql, "LOAD DATA LOCAL INFILE './example.txt' INTO table club")){
		printf( "Failed to write to MySQL: Error: %s\n",  mysql_error(&mysql));
	}else{
		printf( "\nwriting to table club was sucessfull");
	}

	mysql_close(&mysql);

	return 0;
}
