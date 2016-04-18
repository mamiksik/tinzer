//
// Created by Martin Mikšík on 14/04/16.
//

#ifndef KETCHUPHOUSE_MOTORCONTROL_H
#define KETCHUPHOUSE_MOTORCONTROL_H

#include "../../../framework/structures/Coordinate.h"
#include "../../../framework/control/AbstractControl.h"

class EngineControl : public AbstractControl
{
public:
	void process(pair<int, int>);

	void push(Coordinate newCoordinate);

private:
	Coordinate currentCoordinate;
};


#endif //KETCHUPHOUSE_MOTORCONTROL_H
