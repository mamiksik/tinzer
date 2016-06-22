//
// Created by Martin Mikšík
//

#include "UltrasonicModel.h"


bool UltrasonicModel::isGatePenetrated()
{
	return ultrasonicSensor.getDistanceInCm() + 2 < distance;
}