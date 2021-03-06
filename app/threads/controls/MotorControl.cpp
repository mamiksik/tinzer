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
	int dx = newCoordinate.x - currentCoordinate.x;
	int dy = newCoordinate.y - currentCoordinate.y;
	double rotation = currentCoordinate.rotation;

	double xRotation = 0;
	double yRotation = 0;

	if (newCoordinate.x > currentCoordinate.x) {
		xRotation = 0;
	} else {
		xRotation = M_PI;
	}

	if (newCoordinate.y > currentCoordinate.y) {
		yRotation = M_PI_2;
	} else {
		yRotation = 1.5 * M_PI;
	}

	if (yRotation > xRotation) {
		if (dx != 0) {
			Helpers::dump(Helpers::Debug, "Rotate x");
			cout << "Val: " << xRotation << endl;
			rotate(rotation, xRotation, power);
			rotation = currentCoordinate.rotation = xRotation;

			Helpers::dump(Helpers::Debug, "Straight x");
			cout << "Val: " << dx << endl;
			straight(dx, power);
			currentCoordinate.x = newCoordinate.x;
		}

		if (dy != 0) {
			Helpers::dump(Helpers::Debug, "Rotate y");
			cout << "Val: " << yRotation << endl;
			rotate(rotation, yRotation, power);
			currentCoordinate.rotation = yRotation;

			Helpers::dump(Helpers::Debug, "Straight y");
			cout << "Val: " << dy << endl;
			straight(dy, power);
			currentCoordinate.y = newCoordinate.y;
		}

	} else {
		if (dy != 0) {
			Helpers::dump(Helpers::Debug, "Rotate y");
			cout << "Val: " << yRotation << endl;
			rotate(rotation, yRotation, power);
			currentCoordinate.rotation = yRotation;

			Helpers::dump(Helpers::Debug, "Straight y");
			cout << "Val: " << dy << endl;
			straight(dy, power);
			currentCoordinate.y = newCoordinate.y;
		}

		if (dx != 0) {
			Helpers::dump(Helpers::Debug, "Rotate x");
			cout << "Val: " << xRotation << endl;
			rotate(rotation, xRotation, power);
			rotation = currentCoordinate.rotation = xRotation;

			Helpers::dump(Helpers::Debug, "Straight x");
			cout << "Val: " << dx << endl;
			straight(dx, power);
			currentCoordinate.x = newCoordinate.x;
		}
	}
	//TODO: Final rotation
}

void MotorControl::encoderProcess(int updatedLeftEncoder, int updatedRightEncoder)
{
	rightEncoderVal = updatedRightEncoder;
	leftEncoderVal = updatedLeftEncoder;
}

void MotorControl::threadTask()
{
	do {
		if (lock || stepQueue.empty()) {
			continue;
		}


		Helpers::dump(Helpers::Debug, "Instruction");

		int encLeftDest = 0;
		int encRightDest = 0;

		bool leftDone = false;
		bool rightDone = false;

		vector<Instruction> instructions = stepQueue.front();
		stepQueue.pop();

		encLeftDest = leftEncoderVal + instructions[0].tics;
		encRightDest = rightEncoderVal + instructions[1].tics;

		leftEngine.setPower(instructions[0].power);
		rightEngine.setPower(instructions[1].power);

		//TODO: Drive using right motorEncoder too
		do {
			if ((instructions[0].power > 0 && encLeftDest <= leftEncoderVal) ||
			    (instructions[0].power < 0 && encLeftDest >= leftEncoderVal)) {
				leftEngine.setPower(0);
				rightEngine.setPower(0);
				leftDone = true;
			}

			/*if ((instructions[1].power > 0 && encRightDest <= rightEncoderVal) ||
			    (instructions[1].power < 0 && encRightDest >= rightEncoderVal)) {
			}*/

		} while (!leftDone);
	} while (repeatTask);
}


void MotorControl::rotate(double startRotation, double endRotation, int power)
{
	double rotation = calculateRotationDiff(endRotation, startRotation);
	double distance = (WHEEL_DISTANCE * (rotation * (180 / M_PI))) / WHEEL_DIAMETER;

	cout << "Rotation: " << rotation << endl;

	vector<Instruction> item;

	if (rotation > 0) {
		//Right
		item.push_back(Instruction(-distance, -power)); //LeftEngine
		item.push_back(Instruction(distance, power));//RightEngine

	} else {
		//Left
		item.push_back(Instruction(-distance, power)); //LeftEngine
		item.push_back(Instruction(distance, -power)); //RightEngine
	}
	stepQueue.push(item);
}

void MotorControl::straight(double block, int power)
{
	double tics = ENCODER_RESOLUTION * LINE_LEIGHT * abs(block) / (WHEEL_DIAMETER * M_PI);

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
