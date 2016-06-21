//
// Created by Martin Mikšík
//

#ifndef KETCHUPHOUSE_ENCODER_H
#define KETCHUPHOUSE_ENCODER_H

#include <iostream>
#include "../ev3dev.h"
#include "../../../framework/hardware/IEncoder.h"

using ev3dev::address_type;
using namespace Interfaces::Hardware;

namespace Hardware {
	class Encoder : public IEncoder
	{
	public:
		Encoder(address_type motor_pin) : motor(motor_pin)
		{
			motor.set_position(0);
		}

		virtual int getAbsPosition();

		virtual void set(int position);

	private:
		ev3dev::motor motor;
	};
}

#endif //KETCHUPHOUSE_ENCODER_H
