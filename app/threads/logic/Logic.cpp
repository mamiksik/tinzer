//
// Created by Martin Mikšík
//

#include <csignal>
#include "Logic.h"
#include "../../../framework/stopWatch/StopWatch.h"


void Logic::threadTask()
{
	int stackSize = 0;
	int stackMaxSize = 4;
	bool penetrated = false;
	bool gateClosed = false;

	StopWatch watch;
	controller.setPower(DEFAULT_POWER);

	cout << "starting controller run thread" << endl;
	pushStrategy();
	controller.startThread();

	/*Helpers::dump(Helpers::Debug, "Close");
	controller.closeGates();

	Helpers::delay(1000);
	Helpers::dump(Helpers::Debug, "open right");
	controller.openRightGate();

	Helpers::delay(1000);
	Helpers::dump(Helpers::Debug, "open left");
	controller.openLeftGate();

	Helpers::delay(1000);
	controller.closeGates();

	Helpers::delay(1000);
	controller.closeGates();

	Helpers::delay(1000);
	Helpers::dump(Helpers::Debug, "open right");
	controller.openRightGate();*/
	//goHome();

	do {
		/*cout << "LOGIC      " << ultrasonicModel.gateDistance() << endl;*/
		/*if (ultrasonicModel.isGatePenetrated()) {
			if (!penetrated) {
				stackSize++;

				*//*Helpers::dump(Helpers::Info, "Stack have accepted new tin(now contain: %d out of %d)", stackSize,
				              stackMaxSize);*//*
			}
			penetrated = true;
			gateDiode.switchOn();
		} else {
			penetrated = false;
			gateDiode.switchOff();
		}*/

		if(ultrasonicModel.gateDistance() < 10){
			Controller::lock = true;
		}else{
			Controller::lock = false;
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

		if (controller.isEmpty()) {

		}

		Helpers::delay(10);
	} while (repeatTask);
}


void Logic::goHome()
{
	Helpers::dump(Helpers::Info, "Go Home");

	Coordinate home = Coordinate(0, 0, M_PI);

	controller.pause();
	controller.aboard();
	controller.resume();

	controller.closeGates();

	Helpers::dump(Helpers::Info, "Home push");
	controller.push(home);
	Helpers::dump(Helpers::Info, "Home after push");
	bool waitForHome = true;

	while (waitForHome) {
		Helpers::dump(Helpers::Info, "Home wait");
		if (home == controller.getPosition()) {
			controller.unload();
			waitForHome = false;
			raise(SIGINT);
		}
		Helpers::delay(1);
	}

	/*controller.push(Coordinate(3, 5, M_PI_2));
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
	}*/

}


void Logic::pushStrategy()
{
	Helpers::dump(Helpers::Info, "Push strategy");




	controller.push(Coordinate(0, 3, M_PI));
	controller.push(Coordinate(-2, 3, M_PI));

	//controller.push(Coordinate(0, 3, M_PI));
	//controller.push(Coordinate(-3, 3, M_PI * (3/4)));
	//controller.push(Coordinate(-3, 2, 0));

	//controller.push(Coordinate(3, 2, 0));

	//controller.push(Coordinate(3, 2, 0));
	//controller.push(Coordinate(3, 3, M_PI));
	//controller.push(Coordinate(1, 3, M_PI_2));


}