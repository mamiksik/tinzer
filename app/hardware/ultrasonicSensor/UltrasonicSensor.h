//
// Created by Martin Mikšík
//

#ifndef KETCHUPHOUSE_ULTRASONICSENSOR_H
#define KETCHUPHOUSE_ULTRASONICSENSOR_H

#include "../ev3dev.h"
#include "../../../framework/hardware/IUltrasonicSensor.h"

using ev3dev::address_type;

class UltrasonicSensor : public IUltrasonicSensor
{
public:
	UltrasonicSensor(address_type sensor, bool enable) : sensor(sensor)
	{
		if (enable) {
			this->enable();
		} else {
			this->disable();
		}
	}

	ev3dev::ultrasonic_sensor &backdoor()
	{
		return sensor;
	}

	/**
	 * Starts sending ultrasonic signal. Signal can be stopped
	 * by stopSignal. Signal can be heard by another sensor
	 */
	void enable()
	{
		sensor.set_mode(ev3dev::ultrasonic_sensor::mode_us_dist_cm);
	}

	/**
	 * Stop sending ultrasonic signal. Signal can be enabled by
	 * startSignal
	 */
	void disable()
	{
		sensor.set_mode(ev3dev::ultrasonic_sensor::mode_us_listen);
	}

	double getDistanceInCm()
	{
		const auto mode = sensor.mode();
		if (mode != ev3dev::ultrasonic_sensor::mode_us_dist_cm)
			sensor.set_mode(ev3dev::ultrasonic_sensor::mode_us_si_cm);
		double value = (double) sensor.value() / 10;
		sensor.set_mode(mode);
		return value;
	}

private:
	ev3dev::ultrasonic_sensor sensor;
};

#endif //KETCHUPHOUSE_ULTRASONICSENSOR_H
