//
// Created by Martin Mikšík on 25/04/16.
//

#include "Encoder.h"


int Encoder::getAbsPosition()
{
	return motor.position();
	//motor.set_position(0);
}

void Encoder::set(int position)
{
	motor.set_position(position);
}