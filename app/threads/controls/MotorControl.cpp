//
// Created by Martin Mikšík on 14/04/16.
//

#include <cmath>
#include "MotorControl.h"

void MotorControl::run()
{
	vector<Instruction> instructions = itemStack.top();
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

void MotorControl::push(Coordinate newCoordinate)
{
	double newRotation = newCoordinate.angle - stackCoordinate.angle;
	int newX = fabs(newCoordinate.x - stackCoordinate.x); //TODO: ABS?
	int newY = fabs(newCoordinate.y - stackCoordinate.y); //TODO: ABS?


	if (stackCoordinate.x > newCoordinate.x) {
		vector<Instruction> item = {
				Instruction(0, 0), //LeftEngine TODO
				Instruction(0, 0) //RightEngine  TODO
		};
		itemStack.push(item);
	}

	{
		int distance = LINE_LEIGHT * newX;
		vector<Instruction> item = {
				Instruction(distance, power), //LeftEngine
				Instruction(distance, power)  //RightEngine
		};
		itemStack.push(item);
		stackCoordinate.x = newX;
	}

	if (stackCoordinate.y > newCoordinate.y) {
		vector<Instruction> item = {
				Instruction(0, 0), //LeftEngine TODO
				Instruction(0, 0)  //RightEngine  TODO
		};
		itemStack.push(item);
	}

	{
		int distance = LINE_LEIGHT * newY;
		vector<Instruction> item = {
				Instruction(distance, power), //LeftEngine
				Instruction(distance, power)  //RightEngine
		};
		itemStack.push(item);
		stackCoordinate.y = newY;
	}
}


void MotorControl::encoderProcess(pair<int, int> encoderPair)
{
	leftEncoder = encoderPair.first;
	rightEncoder = encoderPair.second;
}
