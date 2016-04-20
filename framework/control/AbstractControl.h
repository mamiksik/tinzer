//
// Created by Martin Mikšík on 13/04/16.
//

#ifndef KETCHUPHOUSE_ABSTRACTCONTROL_H
#define KETCHUPHOUSE_ABSTRACTCONTROL_H

#include "../../app/Config.h"
#include <stack>
#include <vector>
#include "../structures/Coordinate.h"
#include "../structures/Instruction.h"

using namespace std;
using namespace structure;

class AbstractControl
{
public:
	virtual void push(Coordinate item) = 0;

	void pause();

	void resume();

	bool isEmpty();

	bool isReady();

	void aboard();

	InstructionVector getPosition(); // universality?

protected:
	typedef vector<Instruction> InstructionVector;

	bool lock;

	Coordinate currentCoordinate = Coordinate(DEFAULT_ROTATION, DEFAULT_X_POSITION, DEFAULT_Y_POSITION);

	stack itemStack<InstructionVector>;
};


#endif //KETCHUPHOUSE_ABSTRACTCONTROL_H
