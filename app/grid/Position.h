//
// Created by Martin Mikšík
//

#ifndef KETCHUPHOUSE_POSITION_H
#define KETCHUPHOUSE_POSITION_H

#include "../Config.h"
#include "../control/Control.h"

//   1
// 0 # 2
//   3
class Position
{
public:
	Position(int width, int height, Coordinate startCoordinates)
			: sizeX(width),
			  sizeY(height),
			  start(startCoordinates),
			  current(startCoordinates)
	{ }

	void moveToPosition(Coordinate coordinates);

	void moveToHome(void);

private:
	int sizeX;
	int sizeY;

	static const int forwardPower = 50;
	static const int turnPower = 50;

	Coordinate start;
	Coordinate current;

	void makeMove(Instruction instruction);
};


#endif //KETCHUPHOUSE_POSITION_H
