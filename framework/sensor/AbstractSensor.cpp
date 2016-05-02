//
// Created by Martin Mikšík
//

#include "AbstractSensor.h"

std::thread AbstractSensor::threadRun()
{
	return std::thread([=] { run(); });
}
