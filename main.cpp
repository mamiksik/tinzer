#include <iostream>
#include <thread>


#include "app/threads/LogicThread.h"

int main(int argc, char *argv[])
{
	LogicThread logicThread;

	cout << "Starting logic thread" << endl;
	std::thread logicT(logicThread);

	logicT.join();

	return 0;
}