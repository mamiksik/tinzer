//
// Created by Martin Mikšík
//

#ifndef KETCHUPHOUSE_BRAINTHREAD_H
#define KETCHUPHOUSE_BRAINTHREAD_H


#include "../../framework/threading/Threading.h"
#include "controls/motorControl/MotorControl.h"
#include "sensors/motorEncoder/EncoderSensor.h"
#include "controls/gateControl/GateControl.h"
#include "sensors/gateSensor/GateSensor.h"

class BrainThread : public Threading
{
public:
	BrainThread(MotorControl &motorControl, EncoderSensor &encoderSensor, GateControl &gateControl,
	            GateSensor &gateSensor) : motorControl(motorControl), encoderSensor(encoderSensor),
	                                      gateControl(gateControl), gateSensor(gateSensor)
	{}

	virtual ~BrainThread()
	{
		stopThread();
	}

private:
	MotorControl &motorControl;
	EncoderSensor &encoderSensor;
	GateControl &gateControl;
	GateSensor &gateSensor;

	virtual void threadTask();
};


#endif //KETCHUPHOUSE_BRAINTHREAD_H
