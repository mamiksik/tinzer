//
// Created by Martin Mikšík
//

#include "AbstractMotor.h"

void AbstractMotor::aboard()
{
	while (!itemStack.empty()) {
		itemStack.pop();
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
	return itemStack.empty();
}

bool AbstractMotor::isReady()
{
	return lock;
}

vector <Instruction> AbstractMotor::getPosition()
{
	return itemStack.top();
}

std::thread AbstractMotor::threadRun()
{
	return std::thread([=] { run(); });
}