//
// Created by Martin Mikšík
//

#ifndef KETCHUPHOUSE_BRAINTHREAD_H
#define KETCHUPHOUSE_BRAINTHREAD_H


#include "../../framework/threading/Threading.h"
#include "controllers/motors/MotorController.h"

class BrainThread : public Threading
{
public:
	BrainThread(MotorController &motorControl) : motorControl(motorControl)
	{}

	virtual ~BrainThread()
	{
		motorControl.stopThread();
		stopThread();
	}

private:
	MotorController &motorControl;

	virtual void threadTask();
};


#endif //KETCHUPHOUSE_BRAINTHREAD_H
