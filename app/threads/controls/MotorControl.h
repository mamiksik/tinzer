//
// Created by Martin Mikšík on 14/04/16.
//

#ifndef KETCHUPHOUSE_MOTORCONTROL_H
#define KETCHUPHOUSE_MOTORCONTROL_H

#include <thread>
#include "../sensors/IEncoderCallback.h"
#include "../../../framework/structures/Coordinate.h"
#include "../../../framework/control/motors/AbstractControl.h"
#include "../../../framework/hardware/IMotor.h"

class MotorControl : public AbstractControl, public IEncoderCallback
{
public:
	MotorControl(IMotor &leftEngine, IMotor &rightEngine, const Coordinate &currentCoordinate) :
			leftEngine(leftEngine),
			rightEngine(rightEngine),
			currentCoordinate(currentCoordinate),
			stackCoordinate(currentCoordinate)
	{ }


	void encoderProcess(int leftEncoder, int rightEncoder); //TODO: Virtual

	void push(Coordinate newCoordinate);

	void run();

	std::thread runThread()
	{
		return std::thread([=] { run(); });
	}

private:
	const Coordinate currentCoordinate;

	Coordinate stackCoordinate;
	IMotor &leftEngine;

	IMotor &rightEngine;
	int leftEncoder;
	int rightEncoder;

	int power;
};


#endif //KETCHUPHOUSE_MOTORCONTROL_H
