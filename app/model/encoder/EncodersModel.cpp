//
// Created by Martin Mikšík
//

#include <chrono>
#include "EncodersModel.h"

using namespace std;

pair<int, int> EncodersModel::getChassisEncodersValues()
{
	return make_pair(leftMotorEncoder.getAbsPosition(), rightMotorEncoder.getAbsPosition());
}

pair<int, int> EncodersModel::getGateEncodersValues()
{
	return make_pair(leftGateEncoder.getAbsPosition(), rightGateEncoder.getAbsPosition());
}