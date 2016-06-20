//
// Created by Martin Mikšík
//

#include <iostream>
#include "GateSensor.h"
#include "../../../../framework/looper/looper.h"
#include "../../../Config.h"

void GateSensor::threadTask()
{
	looper looper(GATE_COLOR_SENSORS_UPDATE_RATE);

	repeatTask = true;

	do {
		looper.start();

		if (distance - ultrasonicSensor.getDistanceInCm() > 3) {
			Helpers::delay(250);
			if (!penetrate && distance - ultrasonicSensor.getDistanceInCm() > 3) {
				penetrate = true;
				Helpers::dump(Helpers::Debug, "Gate penetrated");
				for (auto *callback: controlsCallbacks) {
					callback->gatePenetrated();
				}
			}
			diode.switchOn();
		} else {
			diode.switchOff();
			if (penetrate) {
				Helpers::dump(Helpers::Debug, "Gate penetrate end");
				Helpers::delay(150);
				penetrate = false;
			}
		}

		looper.compare();
	} while (repeatTask);
}