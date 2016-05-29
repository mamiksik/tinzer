#include <iostream>
#include <thread>


#include "app/threads/MainThread.h"


using namespace std;

int main(int argc, char *argv[])
{
	MainThread mainThread;

	thread logicT(mainThread);

	logicT.join();

	return 0;
}