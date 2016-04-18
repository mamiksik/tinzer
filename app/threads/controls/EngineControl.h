//
// Created by Martin Mikšík on 14/04/16.
//

#ifndef KETCHUPHOUSE_MOTORCONTROL_H
#define KETCHUPHOUSE_MOTORCONTROL_H

#include "CoordinateStructure.h"
#include "../../../framework/control/AbstractControl.h"

class MotorControl : public AbstractControl
{
public:
	void process(CoordinateStructure);
};


#endif //KETCHUPHOUSE_MOTORCONTROL_H
