//
// Created by Martin Mikšík
//

#include "Logic.h"

void Logic::threadTask()
{
	controller.push(Coordinate(1, 3, M_PI_2));

	cout << "starting controller run thread" << endl;
	controller.startThread();

	//controller.push(Coordinate(-3, 1, M_PI_2));

	repeatTask = true;
	while (repeatTask) {
		if (controller.isEmpty()) {
			repeatTask = true;
			//throw std::runtime_error("Out of tasks");
		} else {
			Helpers::delay(10);
			repeatTask = true;
		}
	}
}