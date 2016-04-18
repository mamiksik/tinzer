//
// Created by Martin Mikšík on 13/04/16.
//

#ifndef KETCHUPHOUSE_STACK_H
#define KETCHUPHOUSE_STACK_H

#include <stack>
#include "../structures/Coordinate.h"
#include "../structures/Instruction.h"

using namespace std;
using namespace structure;

class Stack
{
public:
	virtual void push(Coordinate item) = 0;

	void pause();

	void resume();

	bool isEmpty();

	bool isReady();

	void aboard();

	Instruction getPosition(); // universality?

private:
	bool lock;

	stack itemStack<Instruction>;

};


#endif //KETCHUPHOUSE_STACK_H
