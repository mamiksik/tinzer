//
// Created by Martin Mikšík
//

#include "Logic.h"


void Logic::threadTask()
{
	int stackSize = 0;
	int stackMaxSize = 2;
	bool penetrated = false;
	bool gateClosed = false;

	controller.push(Coordinate(0, 4, M_PI_2));

	cout << "starting controller run thread" << endl;
	controller.startThread();

	do {
		cout << "LOGIC      " <<  ultrasonicModel.gateDistance() << endl;
		if (ultrasonicModel.isGatePenetrated()) {
			if (!penetrated) {
				stackSize++;
				Helpers::dump(Helpers::Info, "Stack have accepted new tin(now contain: %d out of %d)", stackSize,
				              stackMaxSize);
			}
			penetrated = true;
			gateDiode.switchOn();
		} else {
			penetrated = false;
			gateDiode.switchOff();
		}

		if (stackSize >= stackMaxSize && !gateClosed) {
			Helpers::delay(3000);
			controller.closeGates();
			gateClosed = true;
		}

		Helpers::delay(1);
	} while (repeatTask);
	//controller.push(Coordinate(1, 0, M_PI_2));
	//controller.push(Coordinate(1, 2, M_PI_2));
	//controller.push(Coordinate(2, 4, M_PI_2));
	//controller.push(Coordinate(-1, 0, M_PI_2));
	//controller.push(Coordinate(1, 0, M_PI_2));
	//controller.push(Coordinate(0, 0, M_PI_2));

	//controller.closeGates();
	//controller.openLeftGate();
	//controller.openRightGate();

	cout << "starting controller run thread" << endl;
//	controller.startThread();

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