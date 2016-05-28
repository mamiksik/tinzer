//
// Created by Martin Mikšík
//

#include <cstdlib>
#include <chrono>
#include <cmath>
#include <thread>
#include "MotorControl.h"

void MotorControl::push(Coordinate newCoordinate)
{

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
		Helpers::dump(Helpers::Debug, "Rotate x");
		rotate(rotation, xRotation, power);
		rotation = currentCoordinate.rotation = xRotation;

		Helpers::dump(Helpers::Debug, "Straight x");
		straight(x, power);
		currentCoordinate.x = x;

		Helpers::dump(Helpers::Debug, "Rotate y");
		rotate(rotation, yRotation, power);
		currentCoordinate.rotation = yRotation;

		Helpers::dump(Helpers::Debug, "Straight y");
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

	//TODO: Final rotation
}

void MotorControl::encoderProcess(int updatedLeftEncoder, int updatedRightEncoder)
{
	rightEncoderVal = updatedRightEncoder;
	leftEncoderVal = updatedLeftEncoder;
}

void MotorControl::run()
{
	while (!stopThread) {
		if (lock || stepQueue.empty()) {
			Helpers::dump(Helpers::Debug, "Empty");
			continue;
		}

		Helpers::delay(2000);

		int encLeftStart = leftEncoderVal;
		int encRightStart = rightEncoderVal;

		bool leftDone = false;
		bool rightDone = false;

		vector<Instruction> instructions = stepQueue.front();
		stepQueue.pop();

		leftEngine.setPower(instructions[0].power);
		rightEngine.setPower(instructions[1].power);

		do {
			if (encLeftStart + instructions[0].tic <= leftEncoderVal ||
			    encLeftStart - instructions[0].tic >= leftEncoderVal) {
				leftEngine.setPower(0);
				rightEngine.setPower(0);
				leftDone = true;
			}

			if (encRightStart + instructions[1].tic <= rightEncoderVal ||
			    encRightStart - instructions[1].tic >= rightEncoderVal) {
				//TODO Right val error
				rightDone = true;
			}

		} while (!leftDone and !rightDone);
	}
}


void MotorControl::rotate(double startRotation, double endRotation, int power)
{
	double rotation = calculateRotationDiff(endRotation, startRotation);
	double distance = (WHEEL_DISTANCE * (rotation * (180 / M_PI))) / WHEEL_DIAMETER;

	vector<Instruction> item = {
			Instruction(distance, power), //LeftEngine
			Instruction(distance, -power) //RightEngine
	};

	stepQueue.push(item);
}

void MotorControl::straight(double block, int power)
{
	//double dump = block;
	//Helpers::dump(Helpers::Debug, "block: %d", dump);
	cout << block;

	double tics = ENCODER_RESOLUTION * LINE_LEIGHT * abs(block) / (WHEEL_DIAMETER * M_PI);

	Helpers::dump(Helpers::Debug, "tics: ");
	cout << tics << endl;

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







