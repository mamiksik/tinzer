//
// Created by Martin Mikšík
//

#ifndef KETCHUPHOUSE_ENCODERSENSOR_H
#define KETCHUPHOUSE_ENCODERSENSOR_H

#include <iostream>
#include "../../../framework/hardware/IEncoder.h"

using namespace std;

class EncodersModel
{
public:
	EncodersModel(IEncoder &leftMotorEncoder, IEncoder &rightMotorEncoder, IEncoder &leftGateEncoder,
	              IEncoder &rightGateEncoder) : leftMotorEncoder(leftMotorEncoder),
	                                            rightMotorEncoder(rightMotorEncoder),
	                                            leftGateEncoder(leftGateEncoder),
	                                            rightGateEncoder(rightGateEncoder)
	{}

	pair<int, int> getChassisEncodersValues();

	pair<int, int> getGateEncodersValues();


protected:
	IEncoder &leftMotorEncoder;
	IEncoder &rightMotorEncoder;

	IEncoder &leftGateEncoder;
	IEncoder &rightGateEncoder;
};


#endif //KETCHUPHOUSE_ENCODERSENSOR_H
