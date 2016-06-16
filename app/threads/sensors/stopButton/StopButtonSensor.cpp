//
// Created by Renata
//

#include <stdexcept>
#include "StopButtonSensor.h"

void StopButtonSensor::threadTask()
{
	while (true) {
		if (button.isPressed()) {
			throw std::runtime_error("Stop button pressed");
		}
	}
}
