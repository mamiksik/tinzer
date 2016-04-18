//
// Created by Martin Mikšík on 14/04/16.
//

#include "EngineControl.h"

void EngineControl::process(pair<int, int>)
{
}

void EngineControl::push(Coordinate newCoordinate)
{
	double newRotation = newCoordinate.angle - currentCoordinate.angle;
	int newX = newCoordinate.x - currentCoordinate.x;
	int newY = newCoordinate.y - currentCoordinate.y;


	vector<Instruction> fisrtMakeTurn(2);
	Instruction leftEngine(100, 5);
	Instruction rightEngine(500, 6);

	fisrtMakeTurn[0] = leftEngine;
	fisrtMakeTurn[1] = rightEngine;

	itemStack.push(fisrtMakeTurn);

	InstructionVector thenGoStraight(2);
	Instruction leftEngine2(100, 5);
	Instruction rightEngine2(500, 6);

	thenGoStraight[0] = leftEngine2;
	thenGoStraight[1] = rightEngine2;

	itemStack.push(thenGoStraight);
};
}
