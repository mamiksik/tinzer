//
// Created by Martin Mikšík on 12/03/16.
//

#ifndef KETCHUPHOUSE_CONTROL_H
#define KETCHUPHOUSE_CONTROL_H

#include <math.h>
#include "../api/Engine.h"

//  + angle || - angle
//
//          /\
//          ||

class Control
{
public:
	Control(double wheelPerimeter, double robotPerimeter, const Engine rightEngine, const Engine leftEngine)
			: wheelPerimeter(M_PI * wheelPerimeter),
			  robotPerimeter(M_PI * robotPerimeter),
			  rightEngine(rightEngine),
			  leftEngine(leftEngine)
	{ }

	double getLastDistanceLeft(void);

	double getLastDistanceRight(void);

	void goStraight(double distance, int power);

	void makeTurn(double angle, int power);

	void stay(void);

private:
	double wheelPerimeter;
	double robotPerimeter;

	int tics;

	Engine leftEngine;
	Engine rightEngine;

};


#endif //KETCHUPHOUSE_CONTROL_H
