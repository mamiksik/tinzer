//
// Created by Martin Mikšík on 14/04/16.
//

#include <cstdlib>
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
		if (leftEncoder >= instructions[0].tic) {
			leftEngine.setPower(0);
		}

		if (rightEncoder >= instructions[1].tic) {
			rightEngine.setPower(0);
		}


		if (rightEncoder >= instructions[1].tic && leftEncoder >= instructions[0].tic) {
			stop = true;
		}

	} while (!stop);

	run();
}

void MotorControl::push(Coordinate newCoordinate)
{
	int newX = std::abs(newCoordinate.x - stackCoordinate.x); //TODO: ABS?
	int newY = std::abs(newCoordinate.y - stackCoordinate.y); //TODO: ABS?

	{
		double newRotation = 3.14 - stackCoordinate.angle;
		double distance = (ROBOT_PERIMETER * newRotation) / WHEEL_PERIMETER;
		vector<Instruction> item = {
				Instruction(distance, 0), //LeftEngine TODO
				Instruction(-distance, 0) //RightEngine  TODO
		};
		itemStack.push(item);

		//TODO: Save to stack
	}

	{
		double ticX = (360 * LINE_LEIGHT * newX) / WHEEL_PERIMETER;
		vector<Instruction> item = {
				Instruction(ticX, power), //LeftEngine
				Instruction(ticX, power)  //RightEngine
		};
		itemStack.push(item);
		stackCoordinate.x = newX;
	}

	//TODO: Y rotation

	{
		double ticY = (360 * LINE_LEIGHT * newY) / WHEEL_PERIMETER;
		vector<Instruction> item = {
				Instruction(ticY, power), //LeftEngine
				Instruction(ticY, power)  //RightEngine
		};
		itemStack.push(item);
		stackCoordinate.y = newY;
	}
}


void MotorControl::encoderProcess(int updatedLeftEncoder, int updatedRightEncoder)
{
	leftEncoder = updatedLeftEncoder;
	rightEncoder = updatedRightEncoder;
}

