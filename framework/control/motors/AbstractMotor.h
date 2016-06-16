//
// Created by Martin Mikšík
//

#ifndef KETCHUPHOUSE_ABSTRACTCONTROL_H
#define KETCHUPHOUSE_ABSTRACTCONTROL_H

#include <stack>
#include <vector>
#include <thread>
#include <queue>

#include "../../../app/Config.h"
#include "../../structures/Instruction.h"
#include "../../structures/Coordinate.h"
#include "../../threading/Threading.h"

using namespace std;
using namespace structure;

class AbstractMotor : public Threading
{
public:
	AbstractMotor() : lock(false)
	{}

	virtual void push(Coordinate item) = 0;

	void pause();

	void resume();

	bool isEmpty();

	bool isReady();

	void aboard();

	vector<Instruction> getPosition();

protected:
	bool lock;

	//TODO lock for multi threading
	queue<vector<Instruction> > stepQueue;
};


#endif //KETCHUPHOUSE_ABSTRACTCONTROL_H
