//
// Created by Martin Mikšík on 13/04/16.
//

#include "Stack.h"

void Stack::aboard()
{
	while (!itemStack.empty()) {
		itemStack.pop();
	}
}

void Stack::pause()
{
	lock = true;
}

void Stack::resume()
{
	lock = false;
}

bool Stack::isEmpty()
{
	return itemStack.empty();
}

bool Stack::isReady()
{
	return lock;
}

auto Stack::getPosition()
{
	return itemStack.pop();
}
