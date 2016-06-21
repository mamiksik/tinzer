//
// Created by Martin Mikšík on 25/04/16.
//

#include "Encoder.h"


int Hardware::Encoder::getAbsPosition()
{
	return motor.position();
}

void Hardware::Encoder::set(int position)
{
	motor.set_position(position);
}
