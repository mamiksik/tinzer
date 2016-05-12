//
// Created by Martin Mikšík on 14/04/16.
//

#include <cstdlib>
#include <chrono>
#include <cmath>
#include <thread>
#include "MotorControl.h"

void MotorControl::push(Coordinate newCoordinate)
{
	std::cout << "Push coordinates called" << std::endl;

	int x = newCoordinate.x - currentCoordinate.x;
	int y = newCoordinate.y - currentCoordinate.y;
	double rotation = currentCoordinate.rotation;
	double xRotation;
	double yRotation;

	if (x > 0) {
		xRotation = 0;
	} else {
		xRotation = M_PI;
	}

	if (y > 0) {
		yRotation = 0.5 * M_PI;
	} else {
		yRotation = 1.5 * M_PI;
	}

	if (yRotation > xRotation) {
		rotate(rotation, xRotation, power);
		currentCoordinate.rotation = xRotation;

		straight(x, power);
		currentCoordinate.x = x;

		rotate(rotation, yRotation, power);
		currentCoordinate.rotation = yRotation;

		straight(y, power);
		currentCoordinate.y = y;

	} else {
		rotate(rotation, yRotation, power);
		currentCoordinate.rotation = yRotation;

		straight(y, power);
		currentCoordinate.y = y;

		rotate(rotation, xRotation, power);
		currentCoordinate.rotation = xRotation;

		straight(x, power);
		currentCoordinate.x = x;
	}
}

void MotorControl::encoderProcess(int updatedLeftEncoder, int updatedRightEncoder)
{
	leftEncoder = abs(updatedLeftEncoder);
	rightEncoder = abs(updatedRightEncoder);
}

void MotorControl::run()
{
	while (!stopThread) {
		if (stepQueue.empty() || lock) {
			continue;
		}

		vector<Instruction> instructions = stepQueue.front();
		stepQueue.pop();

		leftEngine.setPower(instructions[0].power);
		rightEngine.setPower(instructions[1].power);

		bool stop = false;
		do {
			if (leftEncoder >= instructions[0].tic) {
				leftEngine.setPower(0);
			}

			//if (instructions[0].tic == 0) {
			//	leftEngine.setPower(0);
			//}

			if (rightEncoder >= instructions[1].tic) {
				rightEngine.setPower(0);
			}

			//if (instructions[1].tic == 0) {
			//	rightEngine.setPower(0);
			//}

			if (rightEncoder >= instructions[1].tic && leftEncoder >= instructions[0].tic) {
				leftEncoder = 0;
				rightEncoder = 0;
				stop = true;
			}

		} while (!stop);
	}
}


void MotorControl::rotate(double startRotation, double endRotation, int power)
{
	double rotation = calculateRotationDiff(endRotation, startRotation);
	double distance = (ROBOT_PERIMETER * (rotation * (180 / M_PI))) / WHEEL_PERIMETER;

	vector<Instruction> item = {
			Instruction(distance, power), //LeftEngine
			Instruction(distance, -power) //RightEngine
	};

	stepQueue.push(item);
}

void MotorControl::straight(double block, int power)
{
	double tics = abs(360 * LINE_LEIGHT * block) / WHEEL_PERIMETER;
	vector<Instruction> item = {
			Instruction(tics, power), //LeftEngine
			Instruction(tics, power)  //RightEngine
	};
	stepQueue.push(item);
}

double MotorControl::calculateRotationDiff(double startRotation, double endRotation)
{
	if (abs(endRotation - startRotation) < abs(endRotation + 2 * M_PI - startRotation)) {
		return endRotation - startRotation;
	} else {
		return endRotation + 2 * M_PI - startRotation;
	}
}







