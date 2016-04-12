//
// Created by Martin Mikšík on 11/04/16.
//

#ifndef KETCHUPHOUSE_ENCODERSENSOR_H
#define KETCHUPHOUSE_ENCODERSENSOR_H

#include <functional>
#include <vector>

using namespace std;

class EncoderSensor
{
public:
	EncoderSensor(vector<function<void(pair<int, int>)> > &controlsCallbacks) : controlsCallbacks(
			controlsCallbacks)
	{ }

	pair<int, int> read();

protected:

	//vector<function<pair<int, int>()> > controlsCallbacks;
	vector<function<void(pair<int, int>)> > controlsCallbacks;

	int leftEncoder;
	int rightEncoder;

	void update();
};


#endif //KETCHUPHOUSE_ENCODERSENSOR_H
