//
// Created by Martin Mikšík
//

#include "UltrasonicSensor.h"


void UltrasonicSensor::enable()
{
	sensor.set_mode(ev3dev::ultrasonic_sensor::mode_us_dist_cm);
}

void UltrasonicSensor::disable()
{
	sensor.set_mode(ev3dev::ultrasonic_sensor::mode_us_listen);
}

double UltrasonicSensor::getDistanceInCm()
{
	const auto mode = sensor.mode();
	if (mode != ev3dev::ultrasonic_sensor::mode_us_dist_cm)
		sensor.set_mode(ev3dev::ultrasonic_sensor::mode_us_si_cm);
	double value = (double) sensor.value() / 10;
	sensor.set_mode(mode);
	return value;
}