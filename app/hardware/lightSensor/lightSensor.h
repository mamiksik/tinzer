//
// Created by Martin Mikšík
//

#ifndef KETCHUPHOUSE_COLORSENSOR_H
#define KETCHUPHOUSE_COLORSENSOR_H


#include "../ev3dev.h"
#include "../../../framework/hardware/ILightSensor.h"

using ev3dev::address_type;

class LightSensor : public ILightSensor
{
public:
	LightSensor(address_type sensorPort) : sensor(sensorPort)
	{}

	int getAmbient();

private:
	ev3dev::color_sensor sensor;
};


#endif //KETCHUPHOUSE_COLORSENSOR_H
