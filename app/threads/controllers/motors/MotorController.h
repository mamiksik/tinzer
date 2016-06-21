//
// Created by Martin Mikšík on 14/04/16.
//

#ifndef KETCHUPHOUSE_MOTORCONTROL_H
#define KETCHUPHOUSE_MOTORCONTROL_H

#include <iostream>
#include <atomic>
#include "../../../../framework/structures/Coordinate.h"
#include "../../../../framework/control/motors/AbstractMotor.h"
#include "../../../../framework/hardware/IMotor.h"
#include "../../sensors/encoder/EncodersSensor.h"

class MotorController : public AbstractMotor
{
public:
	MotorController(IMotor &leftEngine, IMotor &rightEngine, EncodersSensor &encodersSensor,
	                const Coordinate currentCoordinate, int power) :
			leftEngine(leftEngine),
			rightEngine(rightEngine),
			encodersSensor(encodersSensor),
			startCoordinate(currentCoordinate),
			currentCoordinate(currentCoordinate),
			power(power)
	{}

	virtual ~MotorController()
	{
		stopThread();
	}

	int getPower()
	{
		return power;
	}

	void setPower(int power)
	{
		MotorController::power = power;
	}

	virtual void push(Coordinate newCoordinate);

private:

	IMotor &leftEngine;
	IMotor &rightEngine;

	EncodersSensor &encodersSensor;

	const Coordinate startCoordinate;
	Coordinate currentCoordinate;

	atomic<int> power;

	virtual void threadTask();

	void rotate(double startRotation, double endRotation, int power);

	void straight(double block, int power);

	double calculateRotationDiff(double startRotation, double endRotation);
};


#endif //KETCHUPHOUSE_MOTORCONTROL_H
