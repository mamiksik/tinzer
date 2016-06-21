//
// Created by Martin Mikšík on 14/04/16.
//

#ifndef KETCHUPHOUSE_MOTORCONTROL_H
#define KETCHUPHOUSE_MOTORCONTROL_H

#include <iostream>
#include <atomic>

#include "../../../framework/controller/CoordinateController.h"
#include "../../../framework/structures/Coordinate.h"
#include "../../../framework/hardware/IMotor.h"
#include "../../model/encoder/EncodersModel.h"

using namespace Model;
using namespace Structure;

class Controller : public CoordinateController
{
public:

	Controller(const Coordinate &startCoordinate,
	           int power,
	           EncodersModel &encodersSensor,
	           IMotor &rightChassisMotor,
	           IMotor &leftChassisMotor,
	           IMotor &leftGateMotor,
	           IMotor &rightGateMotor)

			: startCoordinate(startCoordinate),
			  currentCoordinate(startCoordinate),
			  power(power),
			  encodersSensor(encodersSensor),
			  rightChassisMotor(rightChassisMotor),
			  leftChassisMotor(leftChassisMotor),
			  leftGateMotor(leftGateMotor),
			  rightGateMotor(rightGateMotor)
	{}

	virtual ~Controller()
	{
		rightChassisMotor.setPower(0);
		leftChassisMotor.setPower(0);

		leftGateMotor.setPower(0);
		rightGateMotor.setPower(0);

		stopThread();
	}

	virtual void push(Coordinate newCoordinate);

	void closeGate();

	void openLeftGate();

	void openRightGate();

private:

	const Coordinate startCoordinate;
	Coordinate currentCoordinate;

	atomic<int> power;

	EncodersModel &encodersSensor;

	IMotor &rightChassisMotor;
	IMotor &leftChassisMotor;

	IMotor &leftGateMotor;
	IMotor &rightGateMotor;

	virtual void threadTask();
};


#endif //KETCHUPHOUSE_MOTORCONTROL_H
