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
	lockStack = true;
}

void CoordinateController::resume()
{
	lockStack = false;
}

bool CoordinateController::isEmpty()
{
	return stepQueue.empty();
}

bool CoordinateController::isReady()
{
	return !lockStack;
}