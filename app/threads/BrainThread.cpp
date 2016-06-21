//
// Created by Martin Mikšík
//

#include <stdexcept>
#include "BrainThread.h"

void BrainThread::threadTask()
{
	cout << "starting control run thread" << endl;
	motorControl.startThread();

	motorControl.push(Coordinate(3, 3, M_PI_2));
	motorControl.push(Coordinate(-3, 1, M_PI_2));

	repeatTask = true;
	while (repeatTask) {
		if (motorControl.isEmpty()) {
			throw std::runtime_error("Out of tasks");
		} else {
			Helpers::delay(10);
			repeatTask = true;
		}
	}
}