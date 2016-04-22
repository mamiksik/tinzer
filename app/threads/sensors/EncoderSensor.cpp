//
// Created by Martin Mikšík on 11/04/16.
//

#include "EncoderSensor.h"

void EncoderSensor::update()
{
	//Read from hardware

	//Do some stuff

	//Call all callbacks
	for (IEncoderCallback callback: controlsCallbacks) {
		callback.encoderProcess(make_pair(leftEncoder, rightEncoder));
	}
}


pair<int, int> EncoderSensor::read()
{
	return make_pair(leftEncoder, rightEncoder);
}
