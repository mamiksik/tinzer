#include <iostream>
#include <thread>


#include "app/threads/LogicThread.h"
#include "app/threads/ControlThread.h"

using namespace std;

std::mutex mtx;
std::stack<Instruction> instructionsStack;

int main(int argc, char *argv[])
{
	LogicThread logicThread;
	ControlThread controlThread;

	cout << "Starting logic thread" << endl;
	thread logicT(logicThread);

	cout << "Starting control thread" << endl;
	thread controlT(controlThread);

	logicT.join();
	controlT.join();

	return 0;
}