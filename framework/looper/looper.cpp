//
// Created by Martin Mikšík
//


#include <stdexcept>
#include <thread>
#include "looper.h"

void  looper::start()
{
	watch = clock();
}

void  looper::compare()
{
	//Creates deterministic loop
	if (maxLoopTime > (clock() - watch)) {
		//TODO: Sleep
		std::this_thread::sleep_for(milliseconds((clock() - watch)));
	}
	else {
		//throw std::runtime_error("Time overflow");
	}

	watch = clock();
}