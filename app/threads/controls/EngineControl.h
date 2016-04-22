//
// Created by Martin Mikšík on 14/04/16.
//

#ifndef KETCHUPHOUSE_MOTORCONTROL_H
#define KETCHUPHOUSE_MOTORCONTROL_H

#include <cmath>

#include "../sensors/IEncoderCallback.h"
#include "../../../framework/structures/Coordinate.h"
#include "../../../framework/control/engine/AbstractControl.h"
#include "../../../framework/hardware/IEngine.h"

class EngineControl : public AbstractControl, public IEncoderCallback
{
public:

	EngineControl(const Coordinate &currentCoordinate) : currentCoordinate(currentCoordinate)
	{ }

	virtual void encoderProcess(pair<int, int> pair1); //TODO: Virtual

	void run();

private:

	void push(Coordinate newCoordinate);

private:
	Coordinate currentCoordinate;
	Coordinate stackCoordinate = currentCoordinate;

	IEngine leftEngine;
	IEngine rightEngine;

	int leftEncoder;
	int rightEncoder;

	int power;
};


#endif //KETCHUPHOUSE_MOTORCONTROL_H
