//
// Created by Martin Mikšík on 11/04/16.
//

#ifndef KETCHUPHOUSE_ENCODERSENSOR_H
#define KETCHUPHOUSE_ENCODERSENSOR_H

//#include <functional>
#include <vector>
#include "IEncoderCallback.h"
#include "IEncoder.h"
#include "../controls/MotorControl.h"

using namespace std;

class EncoderSensor
{
public:
	EncoderSensor(IEncoder &leftEncoder, IEncoder &rightEncoder, vector<MotorControl> &controlsCallbacks)
			: leftEncoder(leftEncoder),
			  rightEncoder(rightEncoder),
			  controlsCallbacks(controlsCallbacks)
	{ }

	int readLeftEncoder();

	int readRightEncoder();

	std::thread updateThread()
	{
		return std::thread([=] { update(); });
	}

protected:
	vector<MotorControl> &controlsCallbacks;

	IEncoder &leftEncoder;
	IEncoder &rightEncoder;

	void update();
};


#endif //KETCHUPHOUSE_ENCODERSENSOR_H
