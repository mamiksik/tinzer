//
// Created by Martin Mikšík
//

#include "AbstractMotor.h"

void AbstractMotor::aboard()
{
	while (!stepQueue.empty()) {
		stepQueue.pop();
	}
}

void AbstractMotor::pause()
{
	lock = true;
}

void AbstractMotor::resume()
{
	lock = false;
}

bool AbstractMotor::isEmpty()
{
	return stepQueue.empty();
}

bool AbstractMotor::isReady()
{
	return !lock;
}

vector<Instruction> AbstractMotor::getPosition()
{
	return stepQueue.front();
}