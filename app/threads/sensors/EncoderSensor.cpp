//
// Created by Martin Mikšík on 11/04/16.
//

#include "EncoderSensor.h"

void EncoderSensor::update()
{
	//Read from hardware
	int rightEncoderVal = rightEncoder.getRelPosition();
	int leftEncoderVal = leftEncoder.getRelPosition();

	//Do some stuff

	//Call all callbacks
	for (MotorControl &callback: controlsCallbacks) {
		callback.encoderProcess(leftEncoderVal, rightEncoderVal);
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
