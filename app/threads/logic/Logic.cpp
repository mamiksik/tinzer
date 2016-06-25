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

	/*bool seeEnemy = false;
	bool retreat = false;*/
	/*StopWatch watch(false);*/

	StopWatch gameWatch;

	bool stay = true;

	controller.setPower(DEFAULT_POWER);

	Helpers::dump(Helpers::Info, "Starting controller run thread");
	controller.startThread();
	controller.pause();

	vector<Coordinate> strategy = Helpers::loadData("strategy.txt");

	Helpers::dump(Helpers::Info, "Robot is ready and waiting for start");
	gateDiode.switchOn();
	while (stay) {
		if (buttonsModel.isPressedStart()) {
			gameWatch.reset();
			Helpers::dump(Helpers::Info, "1. 2. 3. GO!...");
			controller.resume();
			stay = false;
		}
		Helpers::delay(1);
	}

	loadStraregy(strategy);

	do {
		if (ultrasonicModel.gateDistance() < ENEMY_DETECTION_DISTANCE /*&& !retreat*/) {
			Helpers::dump(Helpers::Warning, "Enemy in range!");
			Controller::lockMotors = true;
		} else {
			Controller::lockMotors = false;

		}

		if (gameWatch.getMs() >= GAME_TIME) {
			goHome();
		}

		/*if(controller.isEmpty()){
			Helpers::dump(Helpers::Info, "%d s to go", (GAME_TIME - gameWatch.getMs()) / 1000);
		}*/

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
	controller.push(home);

	controller.closeGates();

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


void Logic::loadStraregy(vector<Coordinate> strategy)
{
	for(auto coordinate: strategy){
		cout << "X:" << coordinate.x << "Y:" << coordinate.y << "Rotation:" << coordinate.rotation << endl;
		controller.push(coordinate);
	}
}


