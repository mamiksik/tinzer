//
// Created by Martin Mikšík
//

#include <cmath>

#include "Controller.h"

void Controller::push(Coordinate newCoordinate)
{
	double xRotation = 0;
	double yRotation = 0;

	if (newCoordinate.x > expectedCoordinate.x) {
		xRotation = 0;
	} else {
		xRotation = M_PI;
	}

	if (newCoordinate.y > expectedCoordinate.y) {
		yRotation = M_PI_2;
	} else {
		yRotation = 1.5 * M_PI;
	}

	//ToDo: First x or y
	//if (yRotation > xRotation) {
	if (expectedCoordinate.rotation != xRotation) {
		stepQueue.push(Coordinate(expectedCoordinate.x, expectedCoordinate.y, xRotation));
		expectedCoordinate.rotation = xRotation;
	}

	if (expectedCoordinate.x != newCoordinate.x) {
		stepQueue.push(Coordinate(newCoordinate.x, expectedCoordinate.y, xRotation));
		expectedCoordinate.x = newCoordinate.x;
	}

	if (expectedCoordinate.rotation != yRotation) {
		stepQueue.push(Coordinate(expectedCoordinate.x, expectedCoordinate.y, yRotation));
		expectedCoordinate.rotation = yRotation;
	}

	if (expectedCoordinate.y != newCoordinate.y) {
		stepQueue.push(Coordinate(expectedCoordinate.x, newCoordinate.y, yRotation));
		expectedCoordinate.y = newCoordinate.y;
	}
}

void Controller::threadTask()
{
	do {
		Helpers::dump(Helpers::Debug, "thread task");
		if (lock || stepQueue.empty()) {
			continue;
		}

		//array<int, 3> correctionVals = lineModel.getCorectionData();
		array<double, 3> correctionVals;

		correctionVals[0] = 0;
		correctionVals[1] = 0;
		correctionVals[2] = currentCoordinate.rotation;

		Coordinate newCoordinate = stepQueue.front();
		stepQueue.pop();

		if (currentCoordinate.rotation != newCoordinate.rotation) {
			double rotation = correctionVals[2] + newCoordinate.rotation;
			doRotation(rotation);
			currentCoordinate.rotation = currentCoordinate.rotation + rotation;
		}

		if (currentCoordinate.x != newCoordinate.x) {
			int x = 0;
			directionX dirX = whitchDirectionInX(currentCoordinate.x, newCoordinate.x);

			if (dirX == directionX::right) {
				x = LINE_LEIGHT - correctionVals[0];
			} else {
				x = LINE_LEIGHT + correctionVals[0];
			}

			int y = correctionVals[1];

			float c = sqrt(pow(x, 2) + pow(y, 2));

			double alpha = asin((abs(y) * sin(M_PI_2)) / c);

			if ((dirX == directionX::right && y > 0) ||
			    (dirX == directionX::left && y < 0)) {
				alpha = -alpha;
			}
			doRotation(alpha);
			goStraight(static_cast<int>(c));
		}

		if (currentCoordinate.y != newCoordinate.y) {
			int y = 0;
			directionY dirY = whitchDirectionInY(currentCoordinate.y, newCoordinate.y);

			if (dirY == directionY::up) {
				y = LINE_LEIGHT - correctionVals[1];
			} else {
				y = LINE_LEIGHT + correctionVals[1];
			}

			int x = correctionVals[0];

			float c = sqrt(pow(x, 2) + pow(y, 2));

			double alpha = asin((abs(x) * sin(M_PI_2)) / c);

			if ((dirY == directionY::up && x < 0) ||
			    (dirY == directionY::down && x > 0)) {
				alpha = -alpha;
			}
			doRotation(alpha);
			goStraight(static_cast<int>(c));
		}
		repeatTask = true;
	} while (repeatTask);
}

void Controller::doRotation(double rotation)
{
	double tics = (WHEEL_DISTANCE * (rotation * (180 / M_PI))) / WHEEL_DIAMETER;

	pair<int, int> encVals = encodersModel.getChassisEncodersValues();
	int startLeftEncVal = encVals.first;
	int startRightEncVal = encVals.second;

	bool leftMotorEnd = false;
	bool rightMotorEnd = false;

	if (rotation > 0) {
		leftChassisMotor.setPower(-power);
		rightChassisMotor.setPower(power);

		do {
			encVals = encodersModel.getChassisEncodersValues();

			if (encVals.first - startLeftEncVal <= -tics) {
				leftChassisMotor.setPower(0);
				leftMotorEnd = true;
			}

			if (encVals.second - startRightEncVal >= tics) {
				rightChassisMotor.setPower(0);
				rightMotorEnd = true;
			}
		} while (leftMotorEnd && rightMotorEnd);

	} else {
		leftChassisMotor.setPower(power);
		rightChassisMotor.setPower(-power);

		do {
			encVals = encodersModel.getChassisEncodersValues();

			if (encVals.first - startLeftEncVal >= tics) {
				leftChassisMotor.setPower(0);
				leftMotorEnd = true;
			}

			if (encVals.second - startRightEncVal <= -tics) {
				rightChassisMotor.setPower(0);
				rightMotorEnd = true;
			}
		} while (leftMotorEnd && rightMotorEnd);
	}
}

Controller::directionX Controller::whitchDirectionInX(int currentX, int newX)
{
	if (currentX < newX) {
		return directionX::right;
	} else if (currentX > newX) {
		return directionX::left;
	} else {
		return directionX::none;
	}
}

Controller::directionY Controller::whitchDirectionInY(int currentY, int newY)
{
	if (currentY < newY) {
		return directionY::up;
	} else if (currentY > newY) {
		return directionY::down;
	} else {
		return directionY::none;
	}
}

void Controller::goStraight(int distance)
{
	int tics = static_cast<int>(ENCODER_RESOLUTION * distance / (WHEEL_DIAMETER * M_PI));

	pair<int, int> encVals = encodersModel.getChassisEncodersValues();
	int startLeftEncVal = encVals.first;
	int startRightEncVal = encVals.second;

	bool leftMotorEnd = false;
	bool rightMotorEnd = false;

	leftChassisMotor.setPower(power);
	rightChassisMotor.setPower(power);

	do {
		encVals = encodersModel.getChassisEncodersValues();

		if (encVals.first - startLeftEncVal > tics) {
			leftChassisMotor.setPower(0);
			leftMotorEnd = true;
		}

		if (encVals.second - startRightEncVal > tics) {
			rightChassisMotor.setPower(0);
			rightMotorEnd = true;
		}
	} while (leftMotorEnd && rightMotorEnd);


}