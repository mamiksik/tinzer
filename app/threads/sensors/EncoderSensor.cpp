//
// Created by Martin Mikšík on 11/04/16.
//

#include "EncoderSensor.h"

void EncoderSensor::update()
{
	//Read from hardware

	//Do some stuff

	//Call all callbacks
	for (IEncoderCallback &callback: controlsCallbacks) {
		callback.encoderProcess(leftEncoder.getRelPosition(), rightEncoder.getRelPosition());
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
