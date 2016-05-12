#include <iostream>
#include <thread>

#include "app/threads/MainThread.h"

int main(int argc, char *argv[])
{
	MainThread logicThread;

	std::thread logicT(logicThread);
	logicT.join();

	return 0;
}