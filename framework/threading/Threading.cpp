//
// Created by Martin Mikšík
//

#include <iostream>
#include "Threading.h"


void Threading::startThread()
{
	thread = std::thread([&] { threadTask(); });
}

void Threading::stopThread()
{
	repeatTask = false;
	if (thread.joinable()) {
		thread.join();
	}
}