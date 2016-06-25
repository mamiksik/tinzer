//
// Created by Martin Mikšík
//

#include <csignal>
#include "Logic.h"
#include "../../../framework/stopWatch/StopWatch.h"


void Logic::threadTask()
{
	/*int stackSize = 0;
	int stackMaxSize = 4;
	bool penetrated = false;
	bool gateClosed = false;*/
	bool stay = true;

	StopWatch watch;
	controller.setPower(DEFAULT_POWER);

	Helpers::dump(Helpers::Info, "Starting controller run thread");
	controller.startThread();
	controller.pause();

	/*vector<Coordinate> strategy = Helpers::loadData("strategy");

	for(auto coordinate: strategy){
		controller.push(coordinate);
	}*/

	controller.push(Coordinate(0, 1, M_PI_2));

	Helpers::dump(Helpers::Info, "Robot is ready and waiting for start");
	gateDiode.switchOn();
	while (stay) {
		if (buttonsModel.isPressedStart()) {
			Helpers::dump(Helpers::Info, "1. 2. 3. GO!...");
			stay = false;
		}
		Helpers::delay(1);
	}


	do {

		if (ultrasonicModel.gateDistance() < ENEMY_DETECTION_DISTANCE) {
			Helpers::dump(Helpers::Warning, "Enemy in range!");
			Controller::lockMotors = true;
		} else {
			Controller::lockMotors = false;
		}


		/*if (stackSize >= stackMaxSize && !gateClosed) {
			Helpers::delay(3000);
			controller.closeGates();
			gateClosed = true;
		}*/


		//cout << "Time: " <<
		if (watch.getMs() >= GAME_TIME) {
			goHome();
		}

		Helpers::delay(10);
	} while (repeatTask);
}


void Logic::goHome()
{
	Helpers::dump(Helpers::Info, "Going home");

	Coordinate home = Coordinate(0, 0, M_PI);

	controller.pause();
	controller.aboard();
	controller.resume();

	controller.closeGates();

	controller.push(home);
	bool waitForHome = true;

	while (waitForHome) {
		if (home == controller.getPosition()) {
			controller.pause();
			controller.unload();
			Helpers::dump(Helpers::Info, "I am at home");
			waitForHome = false;
			raise(SIGINT);
		}
		Helpers::delay(1);
	}
}


