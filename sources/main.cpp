#include <mysql/mysql.h>
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <unistd.h>
#include "Pet.h"
#include "club.h"
#include "Tabmodel.h"
#include "Connect.h"
#include "File.h"
#include "Query.h"
#include "./MPU6050table.h"
#include <signal.h>


volatile bool stop = false;

void signalHandler( int signum )
{
	std::cout << "Interrupt signal (" << signum << ") received.\n";
	stop = true;

	//	exit(signum);

}


int main(){

	signal(SIGINT, signalHandler); // if the user interrupts the process ctrl+C
	signal(SIGTERM, signalHandler);// if the user kills the process

	printf("\nentree du programme");

	Connect con;
	con.openConnexion();//connexion a la base

	File vectFile;

	MPU6050_table *mcu = new MPU6050_table;
	Pet *pet1 = new Pet;
	club *c1 = new club;
	vectFile.append(pet1);

	while(!stop){

		Pet *pet2 = new Pet("ethel","topless","pomme","f","1994-05-10", "");// we must create the object inside the loop.
		vectFile.append(pet2);
		vectFile.writeToFile();
		Query query2(con,PET,LOAD);
		query2.send();

		if( remove( "./sources/pet.txt" ) != 0 )
			perror( "Error deleting file\n" );
		else
			printf("fichier supprime\n");
		//		mcu->getData();
		//		vectFile.append(mcu);
		//		vectFile.writeToFile();
		//		Query query3(con,MPU,LOAD);
		//		query3.send();
	}

	printf("Exiting cleanly...\n");
	delete(mcu);

	Pet *pet3 = new Pet("maxime","felix","pn","h","1994-05-10", "");
	vectFile.append(pet3);
	vectFile.writeToFile();
	Query query3(con,PET,LOAD);
	query3.send();
	con.close();

	return 0;

}


/*
 * Connect con;
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
 *
 *
 *
 *
 */


