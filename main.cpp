#include <mysql/mysql.h>
#include <stdio.h>
#include <stdlib.h>
#include "Pet.h"
#include "club.h"
#include "Tabmodel.h"
#include "Connect.h"
#include "Request.h"
#include "Query.h"


int main(){

	printf("\nentree du programme");

	Pet *p3 = new Pet;
	Pet *p4 = new Pet;

	club *c1 = new club;
	club *c2 = new club(2,"julien");

	Request file;

	file.append(p3);
	file.append(p4);
	file.append(c1);
	file.append(c2);

	file.writeToFile();

	Connect con;
	con.openConnexion();

	Query query(con, PET, LOAD);

	query.send();//query sent to the sql server

	con.close();

	return 0;
}
