/*
 * MPU6050table.h
 *
 *  Created on: 21 févr. 2016
 *      Author: ethel
 */

#ifndef SOURCES_MPU6050TABLE_H_
#define SOURCES_MPU6050TABLE_H_

#include "Tabmodel.h"
#include "MPU6050.h"

using namespace std;

class MPU6050_table : public Tabmodel {
public:

	struct mpu_t {

		float ax;
		float ay;
		float az;
		float temp;
		string date;

	};

	MPU6050_table();
	virtual ~MPU6050_table();

	virtual void display()const;

	void getData();

	friend std::ofstream& operator<<(std::ofstream& ofs, const mpu_t& c);

	static std::ofstream& filempu;

	static void clean_s();

private:

	mpu_t _mdata;
	MPU6050 _mpu;

};

#endif /* SOURCES_MPU6050TABLE_H_ */
