//
// Created by Martin Mikšík on 12/03/16.
//

#include "Control.h"

double Control::getLastDistanceLeft()
{
	return (leftEngine.getEncoderRel() * wheelPerimeter) / tics;
}

double Control::getLastDistanceRight()
{
	return (rightEngine.getEncoderRel() * wheelPerimeter) / tics;
}

void Control::goStraight(int distance, int power)
{
	double tic = (360 * distance) / wheelPerimeter;

	leftEngine.setPosition(tic, power);
	rightEngine.setPosition(tic, power);
}

//1 = full rotation...
void Control::makeTurn(double angle, int power)
{
	double tic = (robotPerimeter * angle) / wheelPerimeter;

	leftEngine.setPosition(-tic, power);
	rightEngine.setPosition(tic, power);
}

