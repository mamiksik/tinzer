//
// Created by Martin Mikšík on 12/03/16.
//

#ifndef KETCHUPHOUSE_ENGINE_H
#define KETCHUPHOUSE_ENGINE_H


#include "../../../framework/hardware/IMotor.h"

class Motor : public IMotor
{

public:
	virtual void setPower(int power);

	virtual void stop();
};


#endif //KETCHUPHOUSE_ENGINE_H
