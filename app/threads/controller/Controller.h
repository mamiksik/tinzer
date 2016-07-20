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

using namespace Structure;

class Controller : public CoordinateController
{
public:

	enum class directionX
	{
		left = -1, none = 0, right = 1
	};

	enum class directionY
	{
		down = -1, none = 0, up = 1
	};

	Controller(const Coordinate &startCoordinate,
	           int power,
	           EncodersModel &encodersModel,
	           IMotor &rightChassisMotor,
	           IMotor &leftChassisMotor,
	           IMotor &leftGateMotor,
	           IMotor &rightGateMotor)

			: startCoordinate(startCoordinate),
			  expectedCoordinate(startCoordinate),
			  currentCoordinate(startCoordinate),
			  power(power),
			  encodersModel(encodersModel),
			  rightChassisMotor(rightChassisMotor),
			  leftChassisMotor(leftChassisMotor),
			  leftGateMotor(leftGateMotor),
			  rightGateMotor(rightGateMotor),
	          leftGateOpen(true),
	          rightGateOpen(true)
	{}


	static bool lockMotors;

	virtual ~Controller()
	{
		stopThread();
	}

	virtual void push(Coordinate newCoordinate);

	virtual Coordinate getPosition();

	void unload();

	void closeGates();

	void openLeftGate();

	void openRightGate();

	void setPower(int power);

	int getPower() const;

	virtual void aboard();

private:
	const Coordinate startCoordinate;
	Coordinate expectedCoordinate;

	//ToDo: Atomic
	Coordinate currentCoordinate;

	//ToDo: Atomic
	int power;

	EncodersModel &encodersModel;

	IMotor &rightChassisMotor;
	IMotor &leftChassisMotor;

	IMotor &leftGateMotor;
	IMotor &rightGateMotor;

	bool leftGateOpen;
	bool rightGateOpen;

	virtual void threadTask();

	void doRotation(double rotation);

	void goStraight(int distance);

	directionX witchDirectionInX(int currentX, int newX);

	directionY witchDirectionInY(int currentY, int newY);
};


#endif //KETCHUPHOUSE_MOTORCONTROL_H
