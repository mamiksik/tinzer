//
// Created by Martin Mikšík on 14/04/16.
//

#include "EngineControl.h"

void EngineControl::run()
{
	InstructionVector instructions = itemStack.top();
	itemStack.pop();

	leftEngine.setPower(instructions[0].power);
	rightEngine.setPower(instructions[1].power);

	bool stop = false;
	do {
		if (leftEncoder >= instructions[0].distance) {
			leftEngine.setPower(0);
		}

		if (rightEncoder >= instructions[1].distance) {
			rightEngine.setPower(0);
		}


		if (rightEncoder >= instructions[1].distance && leftEncoder >= instructions[0].distance) {
			stop = true;
		}

	} while (!stop);
}

void EngineControl::push(Coordinate newCoordinate)
{
	double newRotation = newCoordinate.angle - stackCoordinate.angle;
	int newX = abs(newCoordinate.x - stackCoordinate.x);
	int newY = abs(newCoordinate.y - stackCoordinate.y);


	if (stackCoordinate.x > newCoordinate.x) {
		InstructionVector item(2);
		item[0] = Instruction(0, 0); //LeftEngine TODO
		item[1] = Instruction(0, 0); //RightEngine  TODO
		itemStack.push(item);
	}

	{
		InstructionVector item(2);
		int distance = LINE_LEIGHT * newX;
		item[0] = Instruction(distance, power); //LeftEngine
		item[1] = Instruction(distance, power); //RightEngine
		itemStack.push(item);
		stackCoordinate.x = newX;
	}

	if (stackCoordinate.y > newCoordinate.y) {
		InstructionVector item(2);
		item[0] = Instruction(0, 0); //LeftEngine TODO
		item[1] = Instruction(0, 0); //RightEngine  TODO
		itemStack.push(item);
	}

	{
		InstructionVector item(2);
		int distance = LINE_LEIGHT * newY;
		item[0] = Instruction(distance, power); //LeftEngine
		item[1] = Instruction(distance, power); //RightEngine
		itemStack.push(item);
		stackCoordinate.y = newY;
	}
}


void EngineControl::encoderProcess(pair<int, int> encoderPair)
{
	leftEncoder = encoderPair.first;
	rightEncoder = encoderPair.second;
}
