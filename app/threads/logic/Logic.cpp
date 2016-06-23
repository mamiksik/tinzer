//
// Created by Martin Mikšík
//

#include "Logic.h"

void Logic::threadTask()
{
	controller.push(Coordinate(1, 0, M_PI_2));
	//controller.push(Coordinate(1, 2, M_PI_2));
	//controller.push(Coordinate(2, 4, M_PI_2));
	controller.push(Coordinate(-1, 0, M_PI_2));
	controller.push(Coordinate(1, 0, M_PI_2));
	//controller.push(Coordinate(0, 0, M_PI_2));

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