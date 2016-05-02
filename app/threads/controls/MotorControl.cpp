//
// Created by Martin Mikšík on 14/04/16.
//

#include <cstdlib>
#include <cmath>
#include <thread>
#include "MotorControl.h"
#include "../../../framework/looper/looper.h"

void MotorControl::run()
{
	//looper loop(MOTOR_CONTROL_UPADTE_RATE);
	bool run = true;

	while (run) {
		std::cout << "MotorControl run loop" << std::endl;
		//loop.start();

		if (itemStack.empty()) {
			continue;
		}

		vector <Instruction> instructions = itemStack.top();
		itemStack.pop();

		std::cout << instructions[0].power << std::endl;
		std::cout << instructions[1].power << std::endl;

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
		//loop.compare();
	}
}

void MotorControl::push(Coordinate newCoordinate)
{
	std::cout << "Push coordinates called" << std::endl;

	int newX = std::abs(newCoordinate.x - stackCoordinate.x); //TODO: ABS?
	int newY = std::abs(newCoordinate.y - stackCoordinate.y); //TODO: ABS?

	{
		double newRotation = M_PI - stackCoordinate.rotation;
		double distance = (ROBOT_PERIMETER * newRotation) / WHEEL_PERIMETER;
		vector<Instruction> item = {
				Instruction(distance, power), //LeftEngine TODO
				Instruction(-distance, power) //RightEngine  TODO
		};
		itemStack.push(item);
		//TODO: Save to stack
		stackCoordinate.rotation = newRotation;
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

	{
		double newRotation = M_PI - stackCoordinate.rotation;
		double distance = (ROBOT_PERIMETER * newRotation) / WHEEL_PERIMETER;
		vector <Instruction> item = {
				Instruction(distance, power), //LeftEngine TODO
				Instruction(-distance, power) //RightEngine  TODO
		};
		itemStack.push(item);
		//TODO: Save to stack
		stackCoordinate.rotation = newRotation;
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

	std::cout << "Push coordinates called ends" << std::endl;
}


void MotorControl::encoderProcess(int updatedLeftEncoder, int updatedRightEncoder)
{
	std::cout << "Encoder process called" << std::endl;

	leftEncoder = updatedLeftEncoder;
	rightEncoder = updatedRightEncoder;

	std::cout << leftEncoder << std::endl;
	std::cout << rightEncoder << std::endl;
}



