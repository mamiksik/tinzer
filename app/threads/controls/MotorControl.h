//
// Created by Martin Mikšík on 14/04/16.
//

#ifndef KETCHUPHOUSE_MOTORCONTROL_H
#define KETCHUPHOUSE_MOTORCONTROL_H

//#include <cmath>

#include "../sensors/IEncoderCallback.h"
#include "../../../framework/structures/Coordinate.h"
#include "../../../framework/control/motors/AbstractControl.h"
#include "../../../framework/hardware/IMotor.h"

class MotorControl : public AbstractControl, public IEncoderCallback
{
public:

public:
	MotorControl(IMotor &leftEngine, IMotor &rightEngine, const Coordinate &currentCoordinate) :
			leftEngine(leftEngine),
			rightEngine(rightEngine),
			currentCoordinate(currentCoordinate)
	{ }


	void encoderProcess(int leftEncoder, int rightEncoder); //TODO: Virtual

	void run();

private:

	Coordinate currentCoordinate;
	Coordinate stackCoordinate = currentCoordinate;

	IMotor &leftEngine;
	IMotor &rightEngine;

	int leftEncoder;
	int rightEncoder;
	int power;

	void push(Coordinate newCoordinate);
};


#endif //KETCHUPHOUSE_MOTORCONTROL_H
