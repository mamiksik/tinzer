//
// Created by Martin Mikšík on 25/04/16.
//

#include "Encoder.h"


int Encoder::getAbsPosition()
{
	return motor.position();
}

void Encoder::set(int position)
{
	motor.set_position(position);
}
