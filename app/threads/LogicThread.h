#include <iostream>
#include <thread>
#include <vector>
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

		//Position position = Position(width, height, startCoordinates, control);

		while (update) {
			system_clock::time_point clock_now = system_clock::now();

			//mtx.lock();
			//coordinatesStack.push(Coordinates(0, 1, 1));
			//mtx.unlock();

			if (system_clock::to_time_t(clock_now) >= stopTime) {
				//TODO: Implement return to home
				Position.
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
