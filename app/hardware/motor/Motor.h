//
// Created by Martin Mikšík
//

#ifndef KETCHUPHOUSE_MOTOR_H
#define KETCHUPHOUSE_MOTOR_H

#include "../../../framework/hardware/IMotor.h"
#include "../ev3dev.h"

using ev3dev::address_type;


class Motor : public IMotor
{
public:

	Motor(address_type motor_pin) : motor(motor_pin)
	{}

	virtual ~Motor()
	{}

	void setPower(int power);

private:
	ev3dev::motor motor;
};


#endif //KETCHUPHOUSE_MOTOR_H
