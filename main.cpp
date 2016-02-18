#include <mysql/mysql.h>
#include <stdio.h>
#include <stdlib.h>
#include "Pet.h"
#include "club.h"
#include "Tabmodel.h"
#include "Connect.h"
#include "File.h"
#include "Query.h"


int main(){

	printf("\nentree du programme");

	Connect con;
	con.openConnexion();//connexion a la base

	File vectFile;

	Pet *p3 = new Pet;
	//	p3->clean_s(); //ok
	Pet *p4 = new Pet;

	club *c1 = new club;
	club *c2 = new club(2,"julien");

	vectFile.append(c1);
	vectFile.append(c2);
	vectFile.append(p3);
	vectFile.append(p4);

	vectFile.writeToFile();

	Query query(con, PET, LOAD);
	Query query2(con, CLUB, LOAD);

	//query.send();//query sent to the sql server
	query2.send();

	con.close();


	return 0;
}
