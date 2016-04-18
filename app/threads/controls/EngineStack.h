//
// Created by Martin Mikšík on 18/04/16.
//

#ifndef KETCHUPHOUSE_ENGINESTACK_H
#define KETCHUPHOUSE_ENGINESTACK_H

#include "../../../framework/control/Stack.h"
#include "../../../framework/structures/Coordinate.h"
#include "../../../framework/structures/Instruction.h"

class EngineStack : public Stack
{
	void push(Coordinate newCoordinate)
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
};


#endif //KETCHUPHOUSE_ENGINESTACK_H
