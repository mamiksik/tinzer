//
// Created by Martin Mikšík on 14/04/16.
//

#include "EngineControl.h"

void EngineControl::process(pair<int, int>)
{
	vector<Instruction> instructions = itemStack.top();
	leftEngine.setPosition(instructions[1].distance, instructions[1].power);
	leftEngine.setPosition(instructions[1].distance, instructions[1].power);
}

void EngineControl::push(Coordinate newCoordinate)
{
	double newRotation = newCoordinate.angle - stackCoordinate.angle;
	int newX = abs(newCoordinate.x - stackCoordinate.x);
	int newY = abs(newCoordinate.y - stackCoordinate.y);


	if (stackCoordinate.x > newCoordinate.x) {
		vector<Instruction> item(2);
		item[0] = Instruction(0, 0); //LeftEngine TODO
		item[1] = Instruction(0, 0); //RightEngine  TODO
		itemStack.push(item);
	}

	{
		vector<Instruction> item(2);
		int distance = LINE_LEIGHT * newX;
		item[0] = Instruction(distance, power); //LeftEngine
		item[1] = Instruction(distance, power); //RightEngine
		itemStack.push(item);
		stackCoordinate.x = newX;
	}

	if (stackCoordinate.y > newCoordinate.y) {
		vector<Instruction> item(2);
		item[0] = Instruction(0, 0); //LeftEngine TODO
		item[1] = Instruction(0, 0); //RightEngine  TODO
		itemStack.push(item);
	}

	{
		vector<Instruction> item(2);
		int distance = LINE_LEIGHT * newY;
		item[0] = Instruction(distance, power); //LeftEngine
		item[1] = Instruction(distance, power); //RightEngine
		itemStack.push(item);
		stackCoordinate.y = newY;
	}
}

