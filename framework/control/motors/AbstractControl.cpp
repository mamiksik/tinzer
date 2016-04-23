//
// Created by Martin Mikšík
//

#include "AbstractControl.h"

void AbstractControl::aboard()
{
	while (!itemStack.empty()) {
		itemStack.pop();
	}
}

void AbstractControl::pause()
{
	lock = true;
}

void AbstractControl::resume()
{
	lock = false;
}

bool AbstractControl::isEmpty()
{
	return itemStack.empty();
}

bool AbstractControl::isReady()
{
	return lock;
}

vector<Instruction> AbstractControl::getPosition()
{
	return itemStack.top();
}
