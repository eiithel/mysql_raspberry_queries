#include <mysql/mysql.h>
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <unistd.h>
#include "Tabmodel.h"
#include "Connect.h"
#include "File.h"
#include "Query.h"
#include "MPU6050table.h"
#include <signal.h>


volatile bool stop = false;

void signalHandler( int signum )
{
	std::cout << "Interrupt signal (" << signum << ") received.\n";
	stop = true;

}


int main(){

	signal(SIGINT, signalHandler); // if the user interrupts the process ctrl+C
	signal(SIGTERM, signalHandler);// if the user kills the process

	printf("\nentree du programme");

	Connect con;
	con.openConnexion();//connexion a la base

	File vectFile;

	while(!stop){

		MPU6050_table *mcu = new MPU6050_table;

		mcu->getData();
		vectFile.append(mcu);
		vectFile.writeToFile();
		Query query3(con,MPU,LOAD);
		query3.send();

		if( remove( "./sources/mpu.txt" ) != 0 )
		perror( "Error deleting file\n" );

		delete(mcu);
		printf("sleep pour 5 secondes");
		sleep(5);

	}

	printf("Exiting cleanly...\n");


	con.close();

	return 0;

}


