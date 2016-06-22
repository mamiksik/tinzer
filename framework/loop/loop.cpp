//
// Created by Martin Mikšík
//


#include "loop.h"

#include <stdexcept>
#include <thread>
#include <iostream>

#include "../Helpers/Helpers.h"

void loop::start()
{
	stopWatch.start();
}

void loop::compare()
{
	stopWatch.stop();
	if (maxLoopTime > stopWatch.getMs()) {
		std::this_thread::sleep_for(milliseconds(stopWatch.getMs()));
	} else if (maxLoopTime < stopWatch.getMs()) {
		Helpers::dump(Helpers::Error, "Time overflow");
		throw std::runtime_error("Time overflow");
	}
}