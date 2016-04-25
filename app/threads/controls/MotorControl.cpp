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
}

void MotorControl::push(Coordinate newCoordinate)
{
	//double newRotation = newCoordinate.angle - stackCoordinate.angle;
	int newX = fabs(newCoordinate.x - stackCoordinate.x); //TODO: ABS?
	int newY = fabs(newCoordinate.y - stackCoordinate.y); //TODO: ABS?

	{
		double newRotation = M_PI - stackCoordinate.angle;
		double distance = (ROBOT_PERIMETER * newRotation) / WHEEL_PERIMETER;
		vector<Instruction> item = {
				Instruction(distance, 0), //LeftEngine TODO
				Instruction(-distance, 0) //RightEngine  TODO
		};
		itemStack.push(item);
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

	if (stackCoordinate.y > newCoordinate.y) {
		vector<Instruction> item = {
				Instruction(0, 0), //LeftEngine TODO
				Instruction(0, 0)  //RightEngine  TODO
		};
		itemStack.push(item);
	}

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
