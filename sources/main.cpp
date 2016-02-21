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

//	MPU6050 mpu(0x68);
//	//	i2cManager i2c;
//
//	//	i2c.connectBus();
//	//	i2c.connectSlave();
//
//	//	int file = i2c.getfd();
//
//	//	mpu.connect();
//	//	mpu.initialize(0);//sensitivity settings = +-2g
//	//	mpu.getAx();
//	//	mpu.getAy();
//	//	mpu.getAz();
//	//
//	//	mpu.convertAccData();
//	//	float temp = mpu.getTemp();
//	//
//	//	printf("\nla temperature est de: %f", temp);
//
//	Connect con;
//	con.openConnexion();//connexion a la base
//
//	File vectFile;
//
//	MPU6050_table *mcu = new MPU6050_table;
//	mcu->getData();
//
//	//	Pet *p3 = new Pet;
//	//	club *c2 = new club(2,"julien");
//
//	vectFile.append(mcu);
//	vectFile.writeToFile();
//
//	Query query3(con, MPU, LOAD);
//	query3.send();

//
//	con.close();

	DEBUG_PRINT("Debugging is enabled.\n");
	DEBUG_PRINT("Debug level: %d", (int) DEBUG);


	return 0;

}


