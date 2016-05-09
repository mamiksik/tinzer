//
// Created by Martin Mikšík on 14/04/16.
//

#ifndef KETCHUPHOUSE_MOTORCONTROL_H
#define KETCHUPHOUSE_MOTORCONTROL_H

#include <iostream>
#include <atomic>
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
		stopThread = false;
	}

	virtual ~MotorControl()
	{
		stopRunThread();
	}

	void startRunThread();

	void stopRunThread();

	virtual void push(Coordinate newCoordinate);

	virtual void encoderProcess(int leftEncoder, int rightEncoder);

private:

	IMotor &leftEngine;
	IMotor &rightEngine;

	const Coordinate currentCoordinate;
	Coordinate stackCoordinate;

	std::atomic<int> leftEncoder;
	std::atomic<int> rightEncoder;
	int power;

	bool stopThread;
	std::thread runThread;

	void run();

	double calculateRotation(double newRotation, double currenRotation);
};


#endif //KETCHUPHOUSE_MOTORCONTROL_H
