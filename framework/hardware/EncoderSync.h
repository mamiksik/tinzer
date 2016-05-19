//
// Created by Martin Mikšík
//

#ifndef KETCHUPHOUSE_ENCODERSYNC_H
#define KETCHUPHOUSE_ENCODERSYNC_H


#include "../../app/threads/sensors/IEncoder.h"
#include "IMotor.h"

class EncoderSync
{
public:

	EncoderSync(IMotor &leftMotor, IMotor &rightMotor, IEncoder &leftEncoder, IEncoder &rightEncoder) : leftMotor(
			leftMotor), rightMotor(rightMotor), leftEncoder(leftEncoder), rightEncoder(rightEncoder)
	{ }

	void sync();

private:
	IMotor &leftMotor;
	IMotor &rightMotor;

	IEncoder &leftEncoder;
	IEncoder &rightEncoder;
};


#endif //KETCHUPHOUSE_ENCODERSYNC_H
