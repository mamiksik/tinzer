//
// Created by Martin Mikšík
//

#ifndef KETCHUPHOUSE_GATECONTROL_H
#define KETCHUPHOUSE_GATECONTROL_H


#include <vector>
#include <queue>
#include "../../../../framework/threading/Threading.h"
#include "../../../../framework/hardware/IMotor.h"
#include "../../sensors/gateSensor/IGateSensorCallback.h"

using namespace std;

class GateControl : public IGateSensorCallback, public Threading
{
public:
	GateControl(IMotor &leftMotor, IMotor &rightMotor, int stackSize) : leftMotor(leftMotor),
	                                                                    rightMotor(rightMotor),
	                                                                    stackMaxSize(stackSize),
	                                                                    stackSize(0),
	                                                                    stackFull(false)
	{
		stepQueue.push(true);
	}


	void release();

private:
	virtual void gatePenetrated();

private:
	IMotor &leftMotor;
	IMotor &rightMotor;

	bool stackFull;

	int stackMaxSize;
	int stackSize;

	//true = open, false = close
	queue<bool> stepQueue;

	virtual void threadTask();
};


#endif //KETCHUPHOUSE_GATECONTROL_H
