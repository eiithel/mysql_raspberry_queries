#include <mysql/mysql.h>
#include <stdio.h>
#include <stdlib.h>
#include "File.h"
#include "Pet.h"
#include "club.h"
#include "Tabmodel.h"
#include "Connect.h"


int main(){

	printf("\nentree du programme");

	Pet *p3 = new Pet;
	Pet *p4 = new Pet;

	club *c1 = new club;
	club *c2 = new club(2,"julien");

	File file;

	file.appendVector(p3);
	file.appendVector(p4);
	file.appendVector(c1);
	file.appendVector(c2);

	file.writeFromvect();

	Connect con;
	con.openConnexion();


	//	if(!mysql_query(&mysql, "INSERT INTO club VALUES( 3 ,'Topless')"))
	//	{ printf("gabi enregistre");//pour marcher avoir exact le bn nombre d'arg en param
	//	}

	//	if(mysql_query(&mysql, "LOAD DATA LOCAL INFILE '~/Documents/json_data/pet.txt' INTO table pet")){
	//		printf( "Failed to write to MySQL: Error: %s\n",  mysql_error(&mysql));
	//	}

	if(mysql_query(&con.mysql, "LOAD DATA LOCAL INFILE './pet.txt' INTO table pet")){
		printf( "Failed to write to MySQL: Error: %s\n",  mysql_error(&con.mysql));
	}else{
		printf( "\nwriting to table club was sucessfull");
	}

	con.close();

	return 0;
}
