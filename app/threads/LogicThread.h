#include <iostream>
#include <thread>
#include "../Config.h"

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

		stopTime = stopTime + Config::getGameTime();

		clock_t watch = clock();
		while (true) {
			//position.moveToPosition(4, 5);
			system_clock::time_point clock_now = system_clock::now();
			if (system_clock::to_time_t(clock_now) >= stopTime) {
				break;
			}

			//Creates deterministic loop
			if (Config::getMaxTimeLoop() > (clock() - watch)) {
				this_thread::sleep_for(milliseconds(1));
			}
			else {
				cout << "loop time overflow" << endl;
			}

			watch = clock();
		}
	}
};
