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
	return itemStack.front();
}

/*
std::thread AbstractMotor::threadRun()
{
	//return std::thread([=] { run(); });
	//return new std::thread([this]{run();});
	std::thread test(&AbstractMotor::run, this);
	return test;
}*/
