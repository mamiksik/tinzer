//
// Created by Martin Mikšík
//

#include "LogicThread.h"

#include <stdexcept>

#include "../../../framework/Helpers/Helpers.h"

void LogicThread::threadTask()
{
	cout << "starting controller run thread" << endl;
	controller.startThread();

	controller.push(Coordinate(3, 3, M_PI_2));
	controller.push(Coordinate(-3, 1, M_PI_2));

	repeatTask = true;
	while (repeatTask) {
		if (controller.isEmpty()) {
			throw std::runtime_error("Out of tasks");
		} else {
			Helpers::delay(10);
			repeatTask = true;
		}
	}
}