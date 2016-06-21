//
// Created by Martin Mikšík
//

#include "ReflectiveSensorBar.h"
#include "../../../../framework/looper/looper.h"

void ReflectiveSensorBar::threadTask()
{
	looper looper(REFLECTIVE_SENSORS_UPDATE_RATE);


	repeatTask = true;

	do {
		looper.start();

		//Read values from hardware
		vector<int> bottom = bottomSensorBar.getData();
		vector<int> right = rightSensorBar.getData();
		vector<int> left = leftSensorBar.getData();



		//Call all callbacks
		//for (IEncoderCallback *callback: controlsCallbacks) {
		//	callback->encoderProcess(leftEncoderVal, rightEncoderVal);
		//}

		looper.compare();
	} while (repeatTask);
}