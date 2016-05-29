//
// Created by Martin Mikšík
//


#ifndef KETCHUPHOUSE_LOOPER_H
#define KETCHUPHOUSE_LOOPER_H

#include <chrono>

using namespace std::chrono;

class looper
{

public:
	looper(int maxLoopTime) : maxLoopTime(maxLoopTime)
	{}

	void start();

	void compare();

private:
	int maxLoopTime;
	clock_t watch = clock();
};


#endif //KETCHUPHOUSE_LOOPER_H
