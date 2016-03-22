//
// Created by Martin Mikšík on 13/03/16.
//

#ifndef KETCHUPHOUSE_POSITION_H
#define KETCHUPHOUSE_POSITION_H

#include "../control/Control.h"


struct Coordinates
{
	Coordinates(int angle, short y, short x)
			: angle(angle), y(y),
			  x(x)
	{ }

	short int y;
	short int x;

	//1 = full rotation
	//Why we wanted to store it as rad?
	int angle;
};

//   1
// 0 # 2
//   3
class Position
{
public:
	Position(int width, int height, int startX, int startY, int startAngle, Control control)
			: sizeX(width),
			  sizeY(height),
			  start(startX, startY, 0),
			  current(startX, startY, startAngle),
			  control(control)
	{ }

	Coordinates getPosition(void);

	Coordinates getStartPosition(void);

	void moveToPosition(short int x, short int y);

private:
	short int sizeX;
	short int sizeY;

	static const int forwardPower = 50;
	static const int turnPower = 50;

	Coordinates start;
	Coordinates current;

	Control control;
};


#endif //KETCHUPHOUSE_POSITION_H
