//
// Created by Martin Mikšík on 14/04/16.
//

#ifndef KETCHUPHOUSE_MOTORCONTROL_H
#define KETCHUPHOUSE_MOTORCONTROL_H

#include "../sensors/IEncoderCallback.h"
#include "../../../framework/structures/Coordinate.h"
#include "../../../framework/control/AbstractControl.h"
#include "../../api/Engine.h"
#include <cmath>

class EngineControl : public AbstractControl, IEncoderCallback
{
public:

	EngineControl(const Coordinate &currentCoordinate) : currentCoordinate(currentCoordinate)
	{ }

	void process(pair<int, int>);

	void push(Coordinate newCoordinate);

private:
	Coordinate currentCoordinate;
	Coordinate stackCoordinate = currentCoordinate;

	Engine leftEngine;
	Engine rightEngine;

	int power;
};


#endif //KETCHUPHOUSE_MOTORCONTROL_H
