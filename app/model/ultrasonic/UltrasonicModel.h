//
// Created by Martin Mikšík
//

#ifndef KETCHUPHOUSE_ULTRASONICMODEL_H
#define KETCHUPHOUSE_ULTRASONICMODEL_H

#include "../../../framework/hardware/IUltrasonicSensor.h"

class UltrasonicModel
{
public:
	UltrasonicModel(IUltrasonicSensor &ultrasonicSensor) : ultrasonicSensor(ultrasonicSensor)
	{
		initGateUltrasonic();
	}

	void initGateUltrasonic();

	void disableGateUltrasonic();

	double gateDistance();

	bool isGatePenetrated();

private:
	double distance;

	IUltrasonicSensor &ultrasonicSensor;
};


#endif //KETCHUPHOUSE_ULTRASONICMODEL_H
