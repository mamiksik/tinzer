//
// Created by Martin Mikšík
//

#ifndef KETCHUPHOUSE_ENCODERSENSOR_H
#define KETCHUPHOUSE_ENCODERSENSOR_H

#include <iostream>
#include <vector>
#include <thread>
#include "IEncoderCallback.h"
#include "IEncoder.h"
#include "../controls/MotorControl.h"
#include "../../../framework/sensor/AbstractSensor.h"

using namespace std;

class EncoderSensor //: public AbstractSensor
{
public:
	//TODO: CallBacks
	EncoderSensor(IEncoder &leftEncoder, IEncoder &rightEncoder, vector<IEncoderCallback *> &controlsCallbacks)
			: leftEncoder(leftEncoder),
			  rightEncoder(rightEncoder),
			  controlsCallbacks(controlsCallbacks)
	{
		stopThread = false;
	}


	virtual ~EncoderSensor()
	{
		stopRunThread();
	}

	int readLeftEncoder();

	int readRightEncoder();

	void startRunThread();

	void stopRunThread();

protected:
	IEncoder &leftEncoder;
	IEncoder &rightEncoder;

	vector<IEncoderCallback *> &controlsCallbacks;

	bool stopThread;
	std::thread runThread;

	void run();
};

#endif //KETCHUPHOUSE_ENCODERSENSOR_H
