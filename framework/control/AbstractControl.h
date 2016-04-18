//
// Created by Martin Mikšík on 13/04/16.
//

#ifndef KETCHUPHOUSE_ABSTRACTCONTROL_H
#define KETCHUPHOUSE_ABSTRACTCONTROL_H

#include "Stack.h"

class AbstractControl
{
public:
	Stack stack;

	virtual void process() = 0;
};


#endif //KETCHUPHOUSE_ABSTRACTCONTROL_H
