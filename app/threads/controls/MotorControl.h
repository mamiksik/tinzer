//
// Created by Martin Mikšík on 14/04/16.
//

#ifndef KETCHUPHOUSE_MOTORCONTROL_H
#define KETCHUPHOUSE_MOTORCONTROL_H

#include <iostream>
#include "../sensors/IEncoderCallback.h"
#include "../../../framework/structures/Coordinate.h"
#include "../../../framework/control/motors/AbstractMotor.h"
#include "../../../framework/hardware/IMotor.h"

class MotorControl : public AbstractMotor, public IEncoderCallback
{
public:
	MotorControl(IMotor &leftEngine, IMotor &rightEngine, const Coordinate currentCoordinate) :
			leftEngine(leftEngine),
			rightEngine(rightEngine),
			currentCoordinate(currentCoordinate),
			stackCoordinate(currentCoordinate)
	{
		power = 40;
	}


	virtual ~MotorControl()
	{ }

	virtual void encoderProcess(int leftEncoder, int rightEncoder);

	virtual void push(Coordinate newCoordinate);

private:

	IMotor &leftEngine;
	IMotor &rightEngine;

	const Coordinate currentCoordinate;
	Coordinate stackCoordinate;

	int leftEncoder;
	int rightEncoder;
	int power;

	virtual void run();
};


#endif //KETCHUPHOUSE_MOTORCONTROL_H
