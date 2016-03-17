//
// Created by Martin Mikšík on 13/03/16.
//

#ifndef KETCHUPHOUSE_POSITION_H
#define KETCHUPHOUSE_POSITION_H

#include "../control/Control.h"

class Position
{
public:
	Position(int width, int height, int startX, int startY, int startAngle, Control control) : sizeX(width),
	                                                                                           sizeY(height),
	                                                                                           start(startX, startY, 0),
	                                                                                           current(startX, startY,
	                                                                                                   startAngle),
	                                                                                           control(control)
	{ }

	Coordinates getPosition(void);

	Coordinates getStartPosition(void);

	void moveToPosition(int x, int y);

private:
	unsigned short int sizeX;
	unsigned short int sizeY;

	Coordinates start;
	Coordinates current;

	Control control;
};

struct Coordinates
{
	Coordinates(double angle, unsigned short y, unsigned short x) : angle(angle), y(y),
	                                                                x(x)
	{ }

	unsigned short int y;
	unsigned short int x;

	//1 = full rotation
	double angle;
};


#endif //KETCHUPHOUSE_POSITION_H
