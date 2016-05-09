//
// Created by Martin Mikšík on 14/04/16.
//

#include <cstdlib>
#include <chrono>
#include <cmath>
#include <thread>
#include "MotorControl.h"

void MotorControl::run()
{
	while (!stopThread) {
		//std::cout << "MotorControl run loop" << std::endl;
		//std::cout << itemStack.size() << std::endl;

		if (itemStack.empty()) {
			continue;
		}

		vector<Instruction> instructions = itemStack.top();
		itemStack.pop();

		leftEngine.setPower(instructions[0].power);
		rightEngine.setPower(instructions[0].power);

		bool stop = false;
		do {
			//std::cout << "--------------" << std::endl;
			//std::cout << leftEncoder << std::endl;
			//std::cout << instructions[0].tic << std::endl;

			if (leftEncoder >= instructions[0].tic) {
				leftEncoder = 0;
				leftEngine.setPower(0);
			}

			if (instructions[0].tic == 0) {
				leftEncoder = 0;
				leftEngine.setPower(0);
			}

			if (rightEncoder >= instructions[1].tic) {
				rightEncoder = 0;
				rightEngine.setPower(0);
			}

			if (instructions[1].tic == 0) {
				rightEncoder = 0;
				rightEngine.setPower(0);
			}

			if (rightEncoder >= instructions[1].tic && leftEncoder >= instructions[0].tic) {
				stop = true;
			}

		} while (!stop);
	}
}

void  MotorControl::startRunThread()
{
	runThread = std::thread([&] { run(); });
}

void MotorControl::stopRunThread()
{
	stopThread = true;
	if (runThread.joinable()) {
		runThread.join();
	}
}

void MotorControl::push(Coordinate newCoordinate)
{
	std::cout << "Push coordinates called" << std::endl;

	int newX = newCoordinate.x - stackCoordinate.x;
	int newY = newCoordinate.y - stackCoordinate.y;
	double actualRotation = stackCoordinate.rotation;

	std::cout << newX << std::endl;
	std::cout << newY << std::endl;
	std::cout << stackCoordinate.rotation << std::endl;


	//std::this_thread::sleep_for(std::chrono::milliseconds(1000));


	double newXRotation;
	double newYRotation;

	if (newX > 0) {
		newXRotation = 0;
	} else {
		newXRotation = M_PI;
	}

	if (newY > 0) {
		newYRotation = 0.5 * M_PI;
	} else {
		newYRotation = 1.5 * M_PI;
	}

	{
		double newRotation = calculateRotation(newXRotation, stackCoordinate.rotation);
		double distance = (ROBOT_PERIMETER * newRotation) / WHEEL_PERIMETER;

		std::cout << "NewRotation" << std::endl;
		std::cout << newRotation << std::endl;
		std::cout << distance << std::endl;
		std::cout << "----------" << std::endl;

		vector<Instruction> item = {
				Instruction(distance, power), //LeftEngine TODO
				Instruction(-distance, -power) //RightEngine  TODO
		};
		itemStack.push(item);
		//TODO: Save to stack
		stackCoordinate.rotation = newXRotation;
	}
/*
	{
		double ticX = abs(360 * LINE_LEIGHT * newX) / WHEEL_PERIMETER;
		std::cout << ticX << std::endl;
		vector<Instruction> item = {
				Instruction(ticX, power), //LeftEngine
				Instruction(ticX, power)  //RightEngine
		};
		itemStack.push(item);
		stackCoordinate.x = newX;
	}

	{
		double newRotation = calculateRotation(newYRotation, stackCoordinate.rotation);
		double distance = (ROBOT_PERIMETER * newRotation) / WHEEL_PERIMETER;
		std::cout << distance << std::endl;
		vector<Instruction> item = {
				Instruction(distance, power), //LeftEngine TODO
				Instruction(-distance, -power) //RightEngine  TODO
		};
		itemStack.push(item);
		//TODO: Save to stack
		stackCoordinate.rotation = newYRotation;
	}

	{
		double ticY = abs(360 * LINE_LEIGHT * newY) / WHEEL_PERIMETER;
		std::cout << ticY << std::endl;
		vector<Instruction> item = {
				Instruction(ticY, power), //LeftEngine
				Instruction(ticY, power)  //RightEngine
		};
		itemStack.push(item);
		stackCoordinate.y = newY;
	}*/

	//std::cout << "Push coordinates called ends" << std::endl;
}


void MotorControl::encoderProcess(int updatedLeftEncoder, int updatedRightEncoder)
{
	//std::cout << "Encoder process called" << std::endl;
	leftEncoder = updatedLeftEncoder;
	rightEncoder = updatedRightEncoder;

	//std::cout << updatedLeftEncoder << std::endl;
	//std::cout << leftEncoder << std::endl;

}

double MotorControl::calculateRotation(double newRotation, double currenRotation)
{
	return abs(newRotation - currenRotation) < abs(newRotation + 2 * M_PI - currenRotation) ? (newRotation -
	                                                                                           currenRotation) : (
			       newRotation + 2 * M_PI - currenRotation);
}



