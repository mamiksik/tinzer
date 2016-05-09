//
// Created by Martin Mikšík on 25/04/16.
//

#include "Encoder.h"


int Encoder::getRelPosition()
{
	int motorPos = motor.position();
	//motor.set_position(0);
	return motorPos;
}