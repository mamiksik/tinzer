#include <iostream>
#include <thread>

#include "app/threads/LogicThread.h"
#include "app/threads/ControlThread.h"

using namespace std;


int main(int argc, char *argv[])
{
	LogicThread logicThread;
	ControlThread controlThread;

	cout << "Starting logic thread" << endl;
	thread controlT(logicThread);

	cout << "Starting control thread" << endl;
	thread realTimeT(controlThread);

	controlT.join();
	realTimeT.join();

	return 0;
}