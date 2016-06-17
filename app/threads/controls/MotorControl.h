//
// Created by Martin Mikšík on 14/04/16.
//

#ifndef KETCHUPHOUSE_MOTORCONTROL_H
#define KETCHUPHOUSE_MOTORCONTROL_H

#include <iostream>
#include <atomic>
#include "../sensors/motorEncoder/IEncoderCallback.h"
#include "../../../framework/structures/Coordinate.h"
#include "../../../framework/control/motors/AbstractMotor.h"
#include "../../../framework/hardware/IMotor.h"

class MotorControl : public AbstractMotor, public IEncoderCallback
{
public:
	MotorControl(IMotor &leftEngine, IMotor &rightEngine, const Coordinate currentCoordinate) :
			leftEngine(leftEngine),
			rightEngine(rightEngine),
			startCoordinate(currentCoordinate),
			currentCoordinate(currentCoordinate),
			power(40),
			leftEncoderVal(0),
			rightEncoderVal(0)
	{}

	virtual ~MotorControl()
	{
		stopThread();
	}

	virtual void push(Coordinate newCoordinate);

	virtual void encoderProcess(int leftEncoder, int rightEncoder);

private:

	IMotor &leftEngine;
	IMotor &rightEngine;

	const Coordinate startCoordinate;
	Coordinate currentCoordinate;

	std::atomic<int> leftEncoderVal;
	std::atomic<int> rightEncoderVal;
	int power;

	virtual void threadTask();

	void rotate(double startRotation, double endRotation, int power);

	void straight(double block, int power);

	double calculateRotationDiff(double startRotation, double endRotation);
};


#endif //KETCHUPHOUSE_MOTORCONTROL_H
