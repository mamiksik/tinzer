//
// Created by Martin Mikšík on 13/04/16.
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

using namespace std;
using namespace structure;

class AbstractMotor
{

public:
	virtual ~AbstractMotor()
	{
		stopRunThread();
	}

	virtual void push(Coordinate item) = 0;

	void pause();

	void resume();

	bool isEmpty();

	bool isReady();

	void aboard();

	vector<Instruction> getPosition();

	void startRunThread();

	void stopRunThread();

protected:
	bool lock;
	bool stopThread;
	std::thread runThread;
	//TODO lock for multi threading
	queue<vector<Instruction> > stepQueue;

	virtual void run() = 0;
};


#endif //KETCHUPHOUSE_ABSTRACTCONTROL_H
