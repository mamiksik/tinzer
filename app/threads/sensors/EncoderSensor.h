//
// Created by Martin Mikšík on 11/04/16.
//

#ifndef KETCHUPHOUSE_ENCODERSENSOR_H
#define KETCHUPHOUSE_ENCODERSENSOR_H

#include <functional>
#include <vector>
#include "IEncoderCallback.h"

using namespace std;

class EncoderSensor
{
public:
	EncoderSensor(vector<IEncoderCallback> &controlsCallbacks) : controlsCallbacks(
			controlsCallbacks)
	{ }

	pair<int, int> read();

protected:
	vector<IEncoderCallback> controlsCallbacks;

	int leftEncoder;
	int rightEncoder;

	void update();
};


#endif //KETCHUPHOUSE_ENCODERSENSOR_H
