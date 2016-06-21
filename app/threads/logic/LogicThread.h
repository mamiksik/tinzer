//
// Created by Martin Mikšík
//

#ifndef KETCHUPHOUSE_BRAINTHREAD_H
#define KETCHUPHOUSE_BRAINTHREAD_H

#include "../../../framework/threading/Threading.h"
#include "../controller/Controller.h"

using namespace std;

class LogicThread : public Threading
{
public:
	LogicThread(Controller &motorControl) : controller(motorControl)
	{}

	virtual ~LogicThread()
	{
		controller.stopThread();
		stopThread();
	}

private:
	Controller &controller;

	virtual void threadTask();
};


#endif //KETCHUPHOUSE_BRAINTHREAD_H
