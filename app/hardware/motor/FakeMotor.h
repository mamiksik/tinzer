//
// Created by Martin Mikšík on 12/03/16.
//

#ifndef KETCHUPHOUSE_ENGINE_H
#define KETCHUPHOUSE_ENGINE_H

#include "../../../framework/hardware/IMotor.h"
#include "../ev3dev.h"

using ev3dev::address_type;


class FakeMotor : public IMotor
{
public:
	void setPower(int power)
	{

	};
};


#endif //KETCHUPHOUSE_ENGINE_H
