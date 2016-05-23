//
// Created by Martin Mikšík on 25/04/16.
//

#ifndef KETCHUPHOUSE_ENCODER_H
#define KETCHUPHOUSE_ENCODER_H

#include <iostream>
#include "../ev3dev.h"
#include "../../threads/sensors/IEncoder.h"

using ev3dev::address_type;

class Encoder : public IEncoder
{
public:
	Encoder(address_type motor_pin, const int fixValue) : motor(motor_pin), fixValue(fixValue)
	{
		motor.set_position(0);
	}

	virtual int getAbsPosition();

	virtual void set(int position);

private:
	const int fixValue;
	ev3dev::motor motor;
};


#endif //KETCHUPHOUSE_ENCODER_H
