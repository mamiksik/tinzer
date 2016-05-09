//
// Created by Martin Mikšík on 12/03/16.
//

//#ifndef KETCHUPHOUSE_ENGINE_H
//#define KETCHUPHOUSE_ENGINE_H

#include "../../../framework/hardware/IMotor.h"
#include "../ev3dev.h"

using ev3dev::address_type;


class Motor : public IMotor
{
public:

	Motor(address_type motor_pin) : motor(motor_pin)
	{ }

	void setPower(int power);

private:
	ev3dev::motor motor;
	//address_type motor;
};


//#endif //KETCHUPHOUSE_ENGINE_H
