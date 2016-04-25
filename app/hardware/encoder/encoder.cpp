//
// Created by Martin Mikšík on 25/04/16.
//

#include "Encoder.h"


int Encoder::getRelPosition()
{
	return motor.count_per_rot();
}