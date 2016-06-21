//
// Created by Martin Mikšík
//

#ifndef KETCHUPHOUSE_ENCODERSENSOR_H
#define KETCHUPHOUSE_ENCODERSENSOR_H

#include <iostream>
#include "../../../../framework/hardware/IEncoder.h"

using namespace std;

class EncodersSensor
{
public:
	EncodersSensor(IEncoder &motorLeftEncoder, IEncoder &motorRightEncoder)
			: motorLeftEncoder(motorLeftEncoder),
			  motorRightEncoder(motorRightEncoder)
	{}


	pair<int, int> getChassisEncodersValues();


protected:
	IEncoder &motorLeftEncoder;
	IEncoder &motorRightEncoder;
};

#endif //KETCHUPHOUSE_ENCODERSENSOR_H
