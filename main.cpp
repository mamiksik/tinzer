#include <iostream>
#include <thread>


#include "app/threads/LogicThread.h"

using namespace std;

int main(int argc, char *argv[])
{
	LogicThread logicThread;

	cout << "Starting logic thread" << endl;
	thread logicT(logicThread);

	logicT.join();

	return 0;
}