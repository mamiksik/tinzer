//
// Created by Renata
//

#include <stdexcept>
#include "ButtonsSensor.h"

bool ButtonsSensor::getStopButton()
{
	return stopButton.isPressed();
}
