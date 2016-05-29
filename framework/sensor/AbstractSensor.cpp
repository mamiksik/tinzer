//
// Created by Martin Mikšík
//

#include "AbstractSensor.h"

void AbstractSensor::startRunThread()
{
	runThread = std::thread([&] { run(); });
}

void AbstractSensor::stopRunThread()
{
	stopThread = true;
	if (runThread.joinable()) {
		runThread.join();
	}
}