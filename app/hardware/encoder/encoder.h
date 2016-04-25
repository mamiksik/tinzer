//
// Created by Martin Mikšík on 25/04/16.
//

#ifndef KETCHUPHOUSE_ENCODER_H
#define KETCHUPHOUSE_ENCODER_H

#include "../ev3dev.h"
#include "../../threads/sensors/IEncoder.h"

using ev3dev::address_type;

class Encoder : public IEncoder
{
public:
	Encoder(address_type motor_pin) : motor(motor_pin)
	{ }

	virtual int getRelPosition();

private:
	ev3dev::motor motor;
};


#endif //KETCHUPHOUSE_ENCODER_H
