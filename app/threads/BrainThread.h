//
// Created by Martin Mikšík
//

#ifndef KETCHUPHOUSE_BRAINTHREAD_H
#define KETCHUPHOUSE_BRAINTHREAD_H


#include "../../framework/threading/Threading.h"
#include "controls/MotorControl.h"
#include "sensors/motorEncoder/EncoderSensor.h"

class BrainThread : public Threading
{
public:
	BrainThread(MotorControl &motorControl, EncoderSensor &encoderSensor) : motorControl(motorControl),
	                                                                        encoderSensor(encoderSensor)
	{}

	virtual ~BrainThread()
	{
		stopThread();
	}

private:
	MotorControl &motorControl;
	EncoderSensor &encoderSensor;

	virtual void threadTask();
};


#endif //KETCHUPHOUSE_BRAINTHREAD_H
