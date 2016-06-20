//
// Created by Martin Mikšík
//

#include "LightSensor.h"

int LightSensor::getAmbient()
{
	sensor.set_mode(ev3dev::color_sensor::mode_col_ambient);
	return sensor.value();
}