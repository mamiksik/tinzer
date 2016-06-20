//
// Created by Martin Mikšík
//

#include <stdexcept>
#include "BrainThread.h"

void BrainThread::threadTask()
{
	//cout << "starting control run thread" << endl;
	motorControl.startThread();

	//cout << "starting motorEncoder run thread" << endl;
	encoderSensor.startThread();

	cout << "starting gateControl run thread" << endl;
	gateSensor.startThread();
	gateControl.startThread();


	motorControl.push(Coordinate(0, 4, 0));

	repeatTask = true;
	while (repeatTask) {
		//if (motorControl.isEmpty()) {
		if (false) {
			//throw std::runtime_error("Out of tasks");
		} else {
			Helpers::delay(10);
			repeatTask = true;
		}
	}
}