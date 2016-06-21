//
// Created by Martin Mikšík
//

#include "UltrasonicModel.h"


bool Model::UltrasonicModel::isGatePenetrated()
{
	return ultrasonicSensor.getDistanceInCm() + 2 < distance;
}