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

int main(){

	printf("\nentree du programme");

//	PRINT_S("\nlol\n");

	MPU6050 mpu(0x68);
	//	i2cManager i2c;


//
//	con.close();

	DEBUG_PRINT("Debugging is enabled.\n");
	DEBUG_PRINT("Debug level: %d", (int) DEBUG);


	return 0;

}


