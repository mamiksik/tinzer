#include "../control/Control.h"
#include "../grid/Position.h"

//Keep just .h or create also .cpp
class ControlThread
{
public:
	void operator()()
	{
		system_clock::time_point clock_now = system_clock::now();
		clock_t watch = clock();

		bool update = true;

		Engine leftEngine = Engine();
		Engine rightEngine = Engine();

		Control control = Control(wheelDiameter, wheelsDistance, leftEngine, rightEngine);

		while (update) {
			system_clock::time_point clock_now = system_clock::now();

			if (mtx.try_lock()) {
				Instruction newInstruction(coordinatesStack.top());
				coordinatesStack.pop();
				mtx.unlock();
				if (newInstruction.action == 1) {
					control.goStraight(newInstruction.distance, newInstruction.power);
				} else if (newInstruction.action == 0) {
					control.makeTurn(newInstruction.distance, newInstruction.power);
				}

				if (coordinatesStack.empty()) {
					control.stay();
				}
			} else {
				control.stay();
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