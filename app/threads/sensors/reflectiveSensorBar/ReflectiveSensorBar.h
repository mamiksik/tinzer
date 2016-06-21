//
// Created by Martin Mikšík
//

#ifndef KETCHUPHOUSE_REFLECTIVESENSORBAR_H
#define KETCHUPHOUSE_REFLECTIVESENSORBAR_H


#include <vector>
#include "IReflectiveSensorBarCallback.h"
#include "../../../../framework/threading/Threading.h"

using namespace std;

class ReflectiveSensorBar : public Threading
{
public:

	ReflectiveSensorBar(IReflectiveBar &bottomSensorBar, IReflectiveBar &leftSensorBar, IReflectiveBar &rightSensorBar,
	                    const vector<IReflectiveBar> &callbacks) : bottomSensorBar(bottomSensorBar),
	                                                               leftSensorBar(leftSensorBar),
	                                                               rightSensorBar(rightSensorBar), callbacks(callbacks)
	{}

private:
	IReflectiveBar &bottomSensorBar;
	IReflectiveBar &leftSensorBar;
	IReflectiveBar &rightSensorBar;

	vector<IReflectiveBar> callbacks;

	virtual void threadTask();
};


#endif //KETCHUPHOUSE_REFLECTIVESENSORBAR_H
