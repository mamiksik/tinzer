//
// Created by Martin Mikšík on 13/04/16.
//

#ifndef KETCHUPHOUSE_ABSTRACTCONTROL_H
#define KETCHUPHOUSE_ABSTRACTCONTROL_H

#include "../../../app/Config.h"
#include <stack>
#include <vector>
#include "../../structures/Instruction.h"
#include "../../structures/Coordinate.h"

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

	vector<Instruction> getPosition(); // universality?

protected:
	bool lock;
	Coordinate currentCoordinate = Coordinate(DEFAULT_ROTATION, DEFAULT_X_POSITION, DEFAULT_Y_POSITION);
	stack<vector<Instruction> > itemStack;
};


#endif //KETCHUPHOUSE_ABSTRACTCONTROL_H
