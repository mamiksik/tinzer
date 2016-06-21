//
// Created by Martin Mikšík
//

#include "CoordinateController.h"

void CoordinateController::aboard()
{
	while (!stepQueue.empty()) {
		stepQueue.pop();
	}
}

void CoordinateController::pause()
{
	lock = true;
}

void CoordinateController::resume()
{
	lock = false;
}

bool CoordinateController::isEmpty()
{
	return stepQueue.empty();
}

bool CoordinateController::isReady()
{
	return !lock;
}