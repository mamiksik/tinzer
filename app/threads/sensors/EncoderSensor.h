//
// Created by Martin Mikšík
//

#ifndef KETCHUPHOUSE_ENCODERSENSOR_H
#define KETCHUPHOUSE_ENCODERSENSOR_H

#include <iostream>
#include <vector>
#include "IEncoderCallback.h"
#include "IEncoder.h"
#include "../controls/MotorControl.h"
#include "../../../framework/sensor/AbstractSensor.h"

using namespace std;

class EncoderSensor : public AbstractSensor
{
public:
	EncoderSensor(IEncoder &leftEncoder, IEncoder &rightEncoder, vector<MotorControl> &controlsCallbacks)
			: leftEncoder(leftEncoder),
			  rightEncoder(rightEncoder),
			  controlsCallbacks(controlsCallbacks)
	{ }

	int readLeftEncoder();

	int readRightEncoder();

protected:
	IEncoder &leftEncoder;
	IEncoder &rightEncoder;

	vector <MotorControl> &controlsCallbacks;

	virtual void run();
};

#endif //KETCHUPHOUSE_ENCODERSENSOR_H
