//
// Created by Martin Mikšík
//

#include <chrono>
#include "EncodersSensor.h"

using namespace std;

pair<int, int> EncodersSensor::getChassisEncodersValues()
{
	return make_pair(motorLeftEncoder.getAbsPosition(), motorRightEncoder.getAbsPosition());
}
