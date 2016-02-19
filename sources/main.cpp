#include <mysql/mysql.h>
#include <stdio.h>
#include <stdlib.h>
#include "Pet.h"
#include "club.h"
#include "Tabmodel.h"
#include "Connect.h"
#include "File.h"
#include "Query.h"
#include "../MPU6050.h"
#include <inttypes.h>

void getAx(int file){

	uint8_t MSB, LSB;
	uint16_t ax;

	MSB = i2c_smbus_read_byte_data(file, MPU6050_RA_ACCEL_XOUT_H);
	LSB = i2c_smbus_read_byte_data(file, MPU6050_RA_ACCEL_XOUT_L);
	ax = (((uint16_t)MSB) << 8) | LSB;

	if (ax < 0){
		printf("\ni2c transaction failed.\n");
		exit(1);
	} else {
		printf("\nax contains the value: %d\n", ax);
	}

}

void getay(int file){
	uint8_t MSB, LSB;
	uint16_t ay;

	MSB = i2c_smbus_read_byte_data(file, MPU6050_RA_ACCEL_YOUT_H);
	LSB = i2c_smbus_read_byte_data(file, MPU6050_RA_ACCEL_YOUT_L);
	ay = (((uint16_t)MSB) << 8) | LSB;

	if (ay < 0){
		printf("\ni2c transaction failed.\n");
		exit(1);
	} else {
		printf("\nay contains the value: %d\n", ay);
	}
}

void getAz(int file){

	uint8_t MSB, LSB;
	uint16_t az;

	MSB = i2c_smbus_read_byte_data(file, MPU6050_RA_ACCEL_ZOUT_H);
	LSB = i2c_smbus_read_byte_data(file, MPU6050_RA_ACCEL_ZOUT_L);
	az = (((uint16_t)MSB) << 8) | LSB;

	if (az < 0){
		printf("\ni2c transaction failed.\n");
		exit(1);
	} else {
		printf("\naz contains the value: %d\n", az);
	}

}


int main(){

	printf("\nentree du programme");

	int addr =0x68;//0b1101000
	int file;//fd
	string filename = "/dev/i2c-1";

	if ((file = open(filename.c_str(), O_RDWR)) < 0) {
		perror("Failed to open the i2c bus");
		exit(1);
	}
	else{
		printf("\nconnected to i2c bus");
		printf("\n");
	}

	if (ioctl(file,I2C_SLAVE,addr) < 0) {
		printf("Failed to acquire bus access and/or talk to slave.\n");
		exit(1);
	}else{
		printf("\n talk to slave is ok");
	}


	getAx(file); //todo a tester en premier

	/*	le test a donné : connected to i2c bus
			talk to slave is ok res contains the real word: 0
			j'ai tjrs la valeur 0 par contre.'a tester avec le 2nd printf
		lire la doc du capteur
	 */


	/*
	float data;
	char buf[10] = {0};
	char channel;

	for(int i = 0; i<4; i++) {
		if (read(file,buf,2) != 2) {
			printf("Failed to read from the i2c bus.\n");
			printf("\n\n");
		} else {
			data = (float)((buf[0] & 0b00001111)<<8)+buf[1];
			data = data/4096*5;
			channel = ((buf[0] & 0b00110000)>>4);
			printf("Channel %02d Data:  %04f\n",channel,data);
		}
	}

	 */

	/*//connexion a la base sql
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

	 */

	return 0;

}


