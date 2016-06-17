//
// Created by Martin Mikšík
//

#ifndef KETCHUPHOUSE_ENCODERSENSOR_H
#define KETCHUPHOUSE_ENCODERSENSOR_H

#include <iostream>
#include <vector>
#include <thread>
#include "IEncoderCallback.h"
#include "../../../../framework/hardware/IEncoder.h"
#include "../../controls/MotorControl.h"

using namespace std;

class EncoderSensor : public Threading
{
public:
	EncoderSensor(IEncoder &leftEncoder, IEncoder &rightEncoder, vector<IEncoderCallback *> &controlsCallbacks)
			: leftEncoder(leftEncoder),
			  rightEncoder(rightEncoder),
			  controlsCallbacks(controlsCallbacks)
	{}

	virtual ~EncoderSensor()
	{
		stopThread();
	}

protected:
	IEncoder &leftEncoder;
	IEncoder &rightEncoder;

	vector<IEncoderCallback *> &controlsCallbacks;

	virtual void threadTask();
};

#endif //KETCHUPHOUSE_ENCODERSENSOR_H
