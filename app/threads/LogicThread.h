//
// Created by Martin Mikšík
//

#ifndef KETCHUPHOUSE_LOGICTHREAD_H
#define KETCHUPHOUSE_LOGICTHREAD_H

#include <iostream>

#include "../Config.h"
#include "../grid/Position.h"

using namespace std;
using namespace chrono;

//Keep just .h or create also .cpp
class LogicThread
{
public:
	void operator()()
	{
		system_clock::time_point clock_now = system_clock::now();
		time_t stopTime = system_clock::to_time_t(clock_now);
		stopTime = stopTime + gameTime;
		clock_t watch = clock();

		bool update = true;

		Position position = Position(width, height, startCoordinates);

		while (update) {
			system_clock::time_point clock_now = system_clock::now();

			position.moveToPosition(Coordinate(1, 1, 0));

			if (system_clock::to_time_t(clock_now) >= stopTime) {
				position.moveToHome();
				break;
			}

			//Creates deterministic loop
			if (maxTimeLoop > (clock() - watch)) {
				this_thread::sleep_for(milliseconds(1));
			}
			else {
				cout << "loop time overflow" << endl;
			}

			watch = clock();
		}
	}
};

#endif //KETCHUPHOUSE_LOGICTHREAD_H