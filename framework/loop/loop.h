//
// Created by Martin Mikšík
//


#ifndef KETCHUPHOUSE_LOOPER_H
#define KETCHUPHOUSE_LOOPER_H

#include <chrono>
#include "../stopWatch/StopWatch.h"

using namespace std::chrono;

class loop
{

public:
	loop(int maxLoopTime) : maxLoopTime(maxLoopTime)
	{}

	void start();

	void compare();

private:
	int maxLoopTime;
	StopWatch stopWatch;
};


#endif //KETCHUPHOUSE_LOOPER_H
