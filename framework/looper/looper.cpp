//
// Created by Martin Mikšík
//


#include <stdexcept>
#include <thread>
#include <iostream>
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
		std::cout << "LESS TIME" << std::endl;
		std::this_thread::sleep_for(milliseconds((clock() - watch)));
	}
	else if (maxLoopTime < (clock() - watch)) {
		//std::cout << "OVERFLOW" << std::endl;
		//throw std::runtime_error("Time overflow");
	}

	watch = clock();
}