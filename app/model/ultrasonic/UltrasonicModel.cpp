//
// Created by Martin Mikšík
//

#include "UltrasonicModel.h"


void UltrasonicModel::initGateUltrasonic()
{
	ultrasonicSensor.enable();
	distance = ultrasonicSensor.getDistanceInCm();
	//ultrasonicSensor.disable();
}


void UltrasonicModel::disableGateUltrasonic()
{
	ultrasonicSensor.disable();
}


float UltrasonicModel::gateDistance()
{
	return ultrasonicSensor.getDistanceInCm();
}


bool UltrasonicModel::isGatePenetrated()
{
	//ultrasonicSensor.enable();
	return ultrasonicSensor.getDistanceInCm() + 2 < distance;
}