//
// Created by Martin Mikšík on 12/03/16.
//

#include "Control.h"
#include <math.h>


void Control::Control(int wheelDiameter, int wheelsDistance, Engine leftEngine,
                      Engine rightEngine)//:wheelPerimeter(M_PI * wheelDiameter)
{
	wheelPerimeter = M_PI * wheelDiameter;
	robotPerimeter = (M_PI * wheelsDistance) / 2;

	leftEngine = leftEngine;
	rightEngine = rightEngine;
}

double Control::getLastDistanceLeft() {
	return (leftEngine.getEncoderRel() * wheelPerimeter) / tics;
}

double Control::getLastDistanceRight() {
	return (rightEngine.getEncoderRel() * wheelPerimeter) / tics;
}

void Control::goStraight(int distance, int power) {
	double tic = (360 * distance) / wheelPerimeter;

	leftEngine.setPosition(tic, power);
	rightEngine.setPosition(tic, power);
}

void Control::makeTurn(int angle, int power) {
	double tic = (robotPerimeter * angle) / wheelPerimeter;

	leftEngine.setPosition(-tic, power);
	rightEngine.setPosition(tic, power);
}