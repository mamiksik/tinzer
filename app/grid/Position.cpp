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

void Position::moveToPosition(short int x, short int y)
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

	//control.calibrateRotation();

	if (newX > current.x) {

		switch (current.angle) {
			case 1:
				control.makeTurn(-0.25, turnPower);
				break;
			case 2:
				control.makeTurn(0.5, turnPower);
				break;
			case 3:
				control.makeTurn(0.25, turnPower);
				break;
		}
		current.angle = 0;
		current.x = x;
		control.goStraight(newX, forwardPower);

	} else if (newX < current.x) {

		switch (current.angle) {
			case 0:
				control.makeTurn(0.5, turnPower);
				break;
			case 1:
				control.makeTurn(0.25, turnPower);
				break;
			case 3:
				control.makeTurn(-0.25, turnPower);
				break;
		}
		current.angle = 2;
		current.x = x;
		control.goStraight(newX, forwardPower);
	}


	if (newY > current.y) {
		switch (current.angle) {
			case 0:
				control.makeTurn(0.25, turnPower);
				break;
			case 2:
				control.makeTurn(-0.25, turnPower);
				break;
		}
		current.angle = 1;
		current.y = y;
		control.goStraight(newX, forwardPower);
	} else if (newY < current.y) {
		switch (current.angle) {
			case 0:
				control.makeTurn(-0.25, turnPower);
				break;
			case 2:
				control.makeTurn(0.25, turnPower);
				break;
		}
		current.angle = 3;
		current.y = y;
		control.goStraight(newX, forwardPower);
	}
}
