#include <iostream>
#include <thread>

#include "app/threads/LogicThread.h"

int main(int argc, char *argv[])
{
	LogicThread logicThread;

	std::cout << "Starting logic thread" << std::endl;
	std::thread logicT(logicThread);

	logicT.join();
	return 0;
}