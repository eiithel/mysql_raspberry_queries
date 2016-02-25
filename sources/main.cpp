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

	Query query3(con,MPU,LOAD);

	while(!stop){
		mcu->getData();
		vectFile.append(mcu);
		vectFile.writeToFile();
		query3.send();
		sleep(10);//we record the data every minute.
	}

	printf("Exiting cleanly...\n");
	con.close();
	delete(mcu);
	//trouver le moyen de vider tous les fichiers

	return 0;

}


