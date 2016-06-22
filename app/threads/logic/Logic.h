//
// Created by Martin Mikšík
//

#ifndef KETCHUPHOUSE_BRAINTHREAD_H
#define KETCHUPHOUSE_BRAINTHREAD_H

#include "../../../framework/threading/Threading.h"
#include "../controller/Controller.h"

using namespace std;

class Logic : public Threading
{
public:
	Logic(Controller &motorControl) : controller(motorControl)
	{}

	virtual ~Logic()
	{
		controller.stopThread();
		stopThread();
	}

private:
	Controller &controller;

	virtual void threadTask();
};


#endif //KETCHUPHOUSE_BRAINTHREAD_H
