//
// Created by Martin Mikšík
//


#include <stdexcept>
#include <thread>
#include <iostream>
#include "looper.h"
#include "../Helpers/Helpers.h"

void looper::start()
{
	stopWatch.start();
}

void looper::compare()
{
	stopWatch.stop();
	if (maxLoopTime > stopWatch.getMs()) {
		std::this_thread::sleep_for(milliseconds(stopWatch.getMs()));
	} else if (maxLoopTime < stopWatch.getMs()) {
		//Helpers::dump(Helpers::Error, "Time overflow");
		//throw std::runtime_error("Time overflow");
	}
}