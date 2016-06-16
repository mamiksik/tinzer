//
// Created by Martin Mikšík
//

#ifndef KETCHUPHOUSE_FAKEMOTOR_H
#define KETCHUPHOUSE_FAKEMOTOR_H

#include "../../../framework/hardware/IMotor.h"

class FakeMotor : public IMotor
{
public:

	FakeMotor()
	{}

	void setPower(int power)
	{

	};
};

#endif //KETCHUPHOUSE_FAKEMOTOR_H
