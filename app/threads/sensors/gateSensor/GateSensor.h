//
// Created by Martin Mikšík
//

#ifndef KETCHUPHOUSE_GATESENSOR_H
#define KETCHUPHOUSE_GATESENSOR_H


#include <vector>
#include <queue>
#include "../../../../framework/hardware/ILightSensor.h"
#include "../../../../framework/threading/Threading.h"
#include "IGateSensorCallback.h"
#include "../../../../framework/Helpers/Helpers.h"
#include "../../../../framework/hardware/IDiode.h"
#include "../../../../framework/hardware/IUltrasonicSensor.h"

using namespace std;

class GateSensor : public Threading
{
public:
	GateSensor(IUltrasonicSensor &ultrasonicSensor,
	           IDiode &diode,
	           vector<IGateSensorCallback *> &controlsCallbacks,
	           const int ERROR) : ultrasonicSensor(ultrasonicSensor),
	                              diode(diode),
	                              controlsCallbacks(controlsCallbacks),
	                              ERROR(ERROR),
	                              penetrate(false)
	{
		diode.switchOff();
		ultrasonicSensor.enable();
		distance = ultrasonicSensor.getDistanceInCm();
	}

private:
	double distance;
	bool penetrate;
	int const ERROR;

	IUltrasonicSensor &ultrasonicSensor;

	IDiode &diode;
	vector<IGateSensorCallback *> &controlsCallbacks;


	virtual void threadTask();
};


#endif //KETCHUPHOUSE_GATESENSOR_H
