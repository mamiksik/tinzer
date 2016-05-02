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
	looper loop(ENCODER_SENSORS_UPDATE_RATE);
	bool run = true;

	while (run) {
		std::cout << "EncoderSensor run loop" << std::endl;
		loop.start();

		//Read from hardware
		int rightEncoderVal = rightEncoder.getRelPosition();
		int leftEncoderVal = leftEncoder.getRelPosition();

		//Do some stuff

		//Call all callbacks
		for (MotorControl &callback: controlsCallbacks) {
			callback.encoderProcess(leftEncoderVal, rightEncoderVal);
		}

		loop.compare();
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
