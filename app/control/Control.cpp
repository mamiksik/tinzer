//
// Created by Martin Mikšík on 12/03/16.
//

#include "Control.h""
#include <math.h>


void Control::Control(int wheelDiameter, int wheelsDistance, Engine leftEngine,
                      Engine rightEngine)//:wheelPerimeter(M_PI * wheelDiameter)
{
	wheelPerimeter = M_PI * wheelDiameter;
	robotPerimeter = (M_PI * wheelsDistance) / 2;

	leftEngine = leftEngine;
	rightEngine = rightEngine;
}

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
void Control::makeTurn(double angleNew, int power)
{
	double tic = (robotPerimeter * angleNew) / wheelPerimeter;

	angle = angleNew;

	leftEngine.setPosition(-tic, power);
	rightEngine.setPosition(tic, power);
}

void Control::calibrateRotation()
{
	//TODO: In future remove and make it clean and more inteligent
	//TODO: Implement return to default rotation
}
