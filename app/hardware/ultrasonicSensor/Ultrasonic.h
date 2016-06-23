//
// Created by Martin Mikšík
//

#ifndef KETCHUPHOUSE_ULTRASONICSENSOR_H
#define KETCHUPHOUSE_ULTRASONICSENSOR_H

#include "../ev3dev.h"
#include "../../../framework/hardware/IUltrasonicSensor.h"

using ev3dev::address_type;

	class Ultrasonic : public IUltrasonicSensor
	{
	public:
		Ultrasonic(address_type sensor, bool enable) : sensor(sensor)
		{
			if (enable) {
				Ultrasonic::enable();
			} else {
				Ultrasonic::disable();
			}
		}

		virtual void enable();

		virtual void disable();

		virtual double getDistanceInCm();

	private:
		ev3dev::ultrasonic_sensor sensor;
	};

#endif //KETCHUPHOUSE_ULTRASONICSENSOR_H
