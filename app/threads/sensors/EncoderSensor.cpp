//
// Created by Martin Mikšík
//

#include <chrono>
#include "EncoderSensor.h"
#include "../../../framework/looper/looper.h"

using namespace std;

void EncoderSensor::threadTask()
{
	looper looper(ENCODER_SENSORS_UPDATE_RATE);

	//Reset encoders
	leftEncoder.set(0);
	rightEncoder.set(0);

	repeatTask = true;

	do {
		looper.start();

		//Read values from hardware
		int leftEncoderVal = leftEncoder.getAbsPosition();
		int rightEncoderVal = rightEncoder.getAbsPosition();

		//Call all callbacks
		for (IEncoderCallback *callback: controlsCallbacks) {
			callback->encoderProcess(leftEncoderVal, rightEncoderVal);
		}

		looper.compare();
	} while (repeatTask);
}
