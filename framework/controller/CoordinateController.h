//
// Created by Martin Mikšík
//

#ifndef KETCHUPHOUSE_ABSTRACTCONTROL_H
#define KETCHUPHOUSE_ABSTRACTCONTROL_H

#include <stack>
#include <vector>
#include <thread>
#include <queue>

#include "../../app/Config.h"
#include "../structures/Instruction.h"
#include "../structures/Coordinate.h"
#include "../threading/Threading.h"

using namespace std;
using namespace Structure;

class CoordinateController : public Threading
{
public:
	CoordinateController() : lockStack(false)
	{}

	virtual void push(Coordinate item) = 0;

	virtual Coordinate getPosition() = 0;

	void aboard();

	void pause();

	void resume();

	bool isEmpty();

	bool isReady();

protected:
	virtual void threadTask() = 0;

	bool lockStack;

	//ToDo: Thread safe
	queue<Coordinate> stepQueue;
};


#endif //KETCHUPHOUSE_ABSTRACTCONTROL_H
