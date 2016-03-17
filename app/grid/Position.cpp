//
// Created by Martin Mikšík on 13/03/16.
//

#include "Position.h"
#include "../control/Control.h"

Coordinates Position::getPosition(void)
{
	return current;
}

Coordinates Position::getStartPosition(void)
{
	return start;
}

void Position::moveToPosition(int x, int y)
{
	int leightOfLine = 90;

	if (x > sizeX) {
		throw "Position X cannot be higher than size of field";
	}

	if (y > sizeY) {
		throw "Position Y cannot be higher than size of field";
	}

	int newX = x * leightOfLine - current.x * leightOfLine;
	int newY = y * leightOfLine - current.y * leightOfLine;

	control.calibrateRotation();

	if (newX > current.x) {
		control.goStraight(newX, 50);
	} else if (newX < current.x) {
		control.makeTurn(0.5, 50);
		control.goStraight(newX, 50);
	}

	current.x = newX;

	control.calibrateRotation();

	if (newY > current.y) {
		control.makeTurn(-0.25, 50);
		control.goStraight(newX, 50);
	} else if (newX < current.x) {
		control.makeTurn(0.25, 50);
		control.goStraight(newX, 50);
	}
	current.y = newY;

	control.calibrateRotation();
}
