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

	//MPU6050_table *mcu = new MPU6050_table;

	printf("\nentree du programme");

	Connect con;
	con.openConnexion();//connexion a la base

	File vectFile;

	Pet *p3 = new Pet;
	Pet *p4= new Pet("TopL","Ethel","monkey","f","","");

	club *c1 = new club;
	club *c2 = new club(2,"julien");

	vectFile.append(c1);
	vectFile.append(c2);
	vectFile.append(p3);
	vectFile.append(p4);

	vectFile.writeToFile();

	Query query(con, PET, LOAD);
	Query query2(con, CLUB, LOAD);

	query2.send();
	query.send();

	while(!stop){
//		mcu->getData();
//		vectFile.append(mcu);
		sleep(60);//we record the data every minute.
	}

	printf("Exiting cleanly...\n");
	con.close();
	//trouver le moyen de vider tous les fichiers

	return 0;

}


