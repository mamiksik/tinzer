//
// Created by Martin Mikšík
//

#ifndef KETCHUPHOUSE_INFRAREDSENSOR_H
#define KETCHUPHOUSE_INFRAREDSENSOR_H

#include "../ev3dev.h"

using ev3dev::address_type;

class InfraredSensor
{
public:
	InfraredSensor(const ev3dev::infrared_sensor sensor) : sensor(sensor)
	{}


private:
	ev3dev::infrared_sensor sensor;
};


#endif //KETCHUPHOUSE_INFRAREDSENSOR_H
