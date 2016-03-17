//
// Created by Martin Mikšík on 12/03/16.
//

#ifndef KETCHUPHOUSE_CONTROL_H
#define KETCHUPHOUSE_CONTROL_H

#include "../api/Engine.h"

//  + angle || - angle
//
//          /\
//          ||

class Control
{
public:
	Control(int wheelDiameter, int wheelsDistance, Engine leftEngine, Engine rightEngine);

	double getLastDistanceLeft(void);

	double getLastDistanceRight(void);

	void goStraight(int distance, int power);

	void makeTurn(double angle, int power);

	void calibrateRotation();

private:
	double wheelPerimeter;
	double robotPerimeter;

	int tics;

	Engine leftEngine;
	Engine rightEngine;

};


#endif //KETCHUPHOUSE_CONTROL_H
