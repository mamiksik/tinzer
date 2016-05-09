//
// Created by Martin Mikšík
//

#include <chrono>
#include "EncoderSensor.h"
#include "../../../framework/looper/looper.h"

using namespace std;
using namespace chrono;


void EncoderSensor::run()
{
	//looper loop(ENCODER_SENSORS_UPDATE_RATE);
	std::cout << "RUN" << std::endl;
	std::cout << stopThread << std::endl;
	while (!stopThread) {

		//std::cout << "EncoderSensor run loop" << std::endl;
		//loop.start();

		//Read from hardware
		int rightEncoderVal = rightEncoder.getRelPosition();
		int leftEncoderVal = leftEncoder.getRelPosition();

		//std::cout << leftEncoderVal << std::endl;

		//Do some stuff

		//Call all callbacks
		for (IEncoderCallback *callback: controlsCallbacks) {
			callback->encoderProcess(leftEncoderVal, rightEncoderVal);
		}
		//stopThread = false;

		//loop.compare();
	}
}


void EncoderSensor::startRunThread()
{
	std::cout << "EncoderSensor thread" << std::endl;
	runThread = std::thread([&] { run(); });
}

void EncoderSensor::stopRunThread()
{
	//TODO Deconstructor is called when create thread(called method startRunThread)
	//stopThread = true;
	if (runThread.joinable()) {
		runThread.join();
	}
}

int EncoderSensor::readLeftEncoder()
{
	return leftEncoder.getRelPosition();
}

int EncoderSensor::readRightEncoder()
{
	return rightEncoder.getRelPosition();
}
