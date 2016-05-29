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
	watch = clock();
}

void looper::compare()
{
	if (maxLoopTime > (clock() - watch)) {
		std::this_thread::sleep_for(milliseconds((clock() - watch)));
	}
	else if (maxLoopTime < (clock() - watch)) {
		Helpers::dump(Helpers::Error, "Time overflow");
		throw std::runtime_error("Time overflow");
	}

	watch = clock();
}