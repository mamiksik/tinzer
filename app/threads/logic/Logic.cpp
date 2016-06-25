//
// Created by Martin Mikšík
//

#include <csignal>
#include "Logic.h"
#include "../../../framework/stopWatch/StopWatch.h"


void Logic::threadTask()
{
	int stackSize = 0;
	int stackMaxSize = 3;
	bool penetrated = false;
	bool gateClosed = false;

	StopWatch watch;
	controller.setPower(DEFAULT_POWER);

	//controller.push(Coordinate(0, 4, M_PI_2));

	cout << "starting controller run thread" << endl;
	pushStrategy();
	controller.startThread();

	/*controller.closeGates();
	goHome();*/

	do {
		cout << "LOGIC      " << ultrasonicModel.gateDistance() << endl;
		if (ultrasonicModel.isGatePenetrated()) {
			if (!penetrated) {
				stackSize++;
				controller.setPower(controller.getPower() + 5);
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


		if (watch.getMs() >= GAME_TIME) {
			goHome();
		}

		if (controller.isEmpty()) {

		}

		Helpers::delay(1);
	} while (repeatTask);


	/*repeatTask = true;
	while (repeatTask) {
		if (controller.isEmpty()) {
			repeatTask = true;
			//throw std::runtime_error("Out of tasks");
		} else {
			Helpers::delay(10);
			repeatTask = true;
		}
	}*/
}


void Logic::goHome()
{
	Helpers::dump(Helpers::Info, "Go Home");

	Coordinate home = Coordinate(0, 0, M_PI);

	controller.pause();
	controller.aboard();
	controller.resume();

	Helpers::dump(Helpers::Info, "Home push");
	controller.push(home);
	Helpers::dump(Helpers::Info, "Home after push");
	bool waitForHome = true;

	while (waitForHome) {
		Helpers::dump(Helpers::Info, "Home wait");
		if (home == controller.getPosition()) {
			controller.unload();
			waitForHome = false;
		}
		Helpers::delay(1);
	}

	controller.push(Coordinate(3, 5, M_PI_2));
	controller.push(Coordinate(3, 6, M_PI));
	controller.push(Coordinate(-3, 6, M_PI));

	controller.push(Coordinate(-1, 0, M_PI));

	home = Coordinate(-1, 0, M_PI);
	waitForHome = true;

	while (waitForHome) {

		cout << "Home " << waitForHome << endl;
		if (home == controller.getPosition()) {
			controller.unload();
			waitForHome = false;
			raise(SIGINT);
		}
		Helpers::delay(1);
	}

}


void Logic::pushStrategy()
{
	Helpers::dump(Helpers::Info, "Push strategy");

	controller.push(Coordinate(0, 3, M_PI));
	controller.push(Coordinate(-2, 3, M_PI));
	controller.push(Coordinate(-2, 1, M_PI));

	//controller.push(Coordinate(0, 3, M_PI));
	//controller.push(Coordinate(-3, 3, M_PI * (3/4)));
	//controller.push(Coordinate(-3, 2, 0));

	//controller.push(Coordinate(3, 2, 0));

	//controller.push(Coordinate(3, 2, 0));
	//controller.push(Coordinate(3, 3, M_PI));
	//controller.push(Coordinate(1, 3, M_PI_2));


}