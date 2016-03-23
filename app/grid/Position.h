//
// Created by Martin Mikšík on 13/03/16.
//

#ifndef KETCHUPHOUSE_POSITION_H
#define KETCHUPHOUSE_POSITION_H

#include "../control/Control.h"
#include "../Config.h"

//   1
// 0 # 2
//   3
class Position
{
public:
	Position(int width, int height, Coordinates coordinates, Control control)
			: sizeX(width),
			  sizeY(height),
			  start(coordinates),
			  current(coordinates),
			  control(control)
	{ }

	Coordinates getPosition(void);

	Coordinates getStartPosition(void);

	void moveToPosition(Coordinates coordinates);

	void stayAtPosition(void);

	void moveToHome(void);

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
