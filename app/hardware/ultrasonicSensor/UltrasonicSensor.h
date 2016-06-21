//
// Created by Martin Mikšík
//

#ifndef KETCHUPHOUSE_ULTRASONICSENSOR_H
#define KETCHUPHOUSE_ULTRASONICSENSOR_H

#include "../ev3dev.h"
#include "../../../framework/hardware/IUltrasonicSensor.h"

using ev3dev::address_type;
using namespace Interfaces::Hardware;

namespace Hardware {
	class UltrasonicSensor : public IUltrasonicSensor
	{
	public:
		UltrasonicSensor(address_type sensor, bool enable) : sensor(sensor)
		{
			if (enable) {
				UltrasonicSensor::enable();
			} else {
				UltrasonicSensor::disable();
			}
		}

		virtual void enable();

		virtual void disable();

		virtual double getDistanceInCm();

	private:
		ev3dev::ultrasonic_sensor sensor;
	};
}

#endif //KETCHUPHOUSE_ULTRASONICSENSOR_H
