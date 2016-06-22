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

	cout << "xRotation: " << xRotation << endl;

	if (newCoordinate.y > expectedCoordinate.y) {
		yRotation = M_PI_2;
	} else {
		yRotation = 1.5 * M_PI;
	}

	//ToDo: First x or y
	//if (yRotation > xRotation) {
	if (expectedCoordinate.x != newCoordinate.x) {

		if (expectedCoordinate.rotation != xRotation) {
			cout << "1. xrot X: " << expectedCoordinate.x << " Y: " << expectedCoordinate.y << " Rot: " << xRotation
			     << endl;
			stepQueue.push(Coordinate(expectedCoordinate.x, expectedCoordinate.y, xRotation));
			expectedCoordinate.rotation = xRotation;
		}


		cout << "2. new x X: " << newCoordinate.x << " Y: " << expectedCoordinate.y << " Rot: "
		     << expectedCoordinate.rotation << endl;
		stepQueue.push(Coordinate(newCoordinate.x, expectedCoordinate.y, xRotation));
		expectedCoordinate.x = newCoordinate.x;
	}


	if (expectedCoordinate.y != newCoordinate.y) {

		if (expectedCoordinate.rotation != yRotation) {
			cout << "3. y rot X: " << expectedCoordinate.x << " Y: " << expectedCoordinate.y << " Rot: " << yRotation
			     << endl;
			stepQueue.push(Coordinate(expectedCoordinate.x, expectedCoordinate.y, yRotation));
			expectedCoordinate.rotation = yRotation;
		}


		cout << "4. new y X: " << expectedCoordinate.x << " Y: " << newCoordinate.y << " Rot: "
		     << expectedCoordinate.rotation << endl;
		stepQueue.push(Coordinate(expectedCoordinate.x, newCoordinate.y, yRotation));
		expectedCoordinate.y = newCoordinate.y;
	}

	Helpers::delay(2000);
}

void Controller::threadTask()
{
	do {
		//Helpers::dump(Helpers::Debug, "thread task");
		if (lock || stepQueue.empty()) {
			//Helpers::dump(Helpers::Debug, "eempty");
			Helpers::delay(1);
			continue;
		}

		//array<int, 3> correctionVals = lineModel.getCorectionData();
		array<double, 3> correctionVals;

		correctionVals[0] = 0;
		correctionVals[1] = 0;
		correctionVals[2] = 0;

		Coordinate newCoordinate = stepQueue.front();
		stepQueue.pop();

		if (currentCoordinate.rotation != newCoordinate.rotation) {
			double rotation = correctionVals[2] + newCoordinate.rotation - currentCoordinate.rotation;


			cout << "tt_roT newC: " << newCoordinate.rotation << "  corV: " << correctionVals[2]
			     << "  curR: " << currentCoordinate.rotation
			     << "  rot: " << rotation << endl;

			doRotation(rotation);
			currentCoordinate.rotation = currentCoordinate.rotation + rotation;
		}

		if (currentCoordinate.x != newCoordinate.x) {
			Helpers::dump(Helpers::Debug, "i am here");
			int x = 0;
			directionX dirX = whitchDirectionInX(currentCoordinate.x, newCoordinate.x);

			if (dirX == directionX::right) {
				x = LINE_LEIGHT - correctionVals[0];
			} else {
				x = LINE_LEIGHT + correctionVals[0];
			}

			cout << x << endl;

			int y = correctionVals[1];

			float c = sqrt(pow(x, 2) + pow(y, 2));

			double alpha = asin((abs(y) * sin(M_PI_2)) / c);

			if ((dirX == directionX::right && y > 0) ||
			    (dirX == directionX::left && y < 0)) {
				alpha = -alpha;
			}

			cout << "Do rotation" << endl;
			//doRotation(alpha);

			cout << "c: " << c << endl;
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
	int tics = static_cast<int>((WHEEL_DISTANCE * (rotation * (180 / M_PI))) / WHEEL_DIAMETER);

	cout << tics << endl;

	pair<int, int> encVals = encodersModel.getChassisEncodersValues();
	int startLeftEncVal = encVals.first;
	int startRightEncVal = encVals.second;

	bool leftMotorEnd = false;
	bool rightMotorEnd = false;

	if (rotation > 0) {
		leftChassisMotor.setPower(-40);
		rightChassisMotor.setPower(40);

		do {

			cout << encVals.first - startLeftEncVal << "  " << encVals.second - startRightEncVal
			     << "  (rot+" << tics << ")" << endl;
			//Helpers::dump(Helpers::Debug, "rotation");

			encVals = encodersModel.getChassisEncodersValues();

			if (encVals.first - startLeftEncVal <= -tics) {
				leftChassisMotor.setPower(0);
				leftMotorEnd = true;
				Helpers::dump(Helpers::Warning, "rot - leftMotorEnd");
			}

			if (encVals.second - startRightEncVal >= tics) {
				rightChassisMotor.setPower(0);
				rightMotorEnd = true;
				Helpers::dump(Helpers::Warning, "rot - rightMotorEnd");
			}
		} while (!leftMotorEnd || !rightMotorEnd);

	} else {
		leftChassisMotor.setPower(power);
		rightChassisMotor.setPower(-power);

		do {

			cout << encVals.first - startLeftEncVal << "  " << encVals.second - startRightEncVal
			     << "  (rot-: " << tics << ")" << endl;

			encVals = encodersModel.getChassisEncodersValues();

			if (encVals.first - startLeftEncVal >= -tics) {
				leftChassisMotor.setPower(0);
				leftMotorEnd = true;
				Helpers::dump(Helpers::Warning, "rot - leftMotorEnd");
			}

			if (encVals.second - startRightEncVal <= tics) {
				rightChassisMotor.setPower(0);
				rightMotorEnd = true;
				Helpers::dump(Helpers::Warning, "rot - rightMotorEnd");
			}
		} while (!leftMotorEnd || !rightMotorEnd);
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
	cout << tics << endl;

	pair<int, int> encVals = encodersModel.getChassisEncodersValues();
	int startLeftEncVal = encVals.first;
	int startRightEncVal = encVals.second;

	bool leftMotorEnd = false;
	bool rightMotorEnd = false;

	leftChassisMotor.setPower(power);
	rightChassisMotor.setPower(power);

	do {
		//Helpers::dump(Helpers::Debug, "straight");
		cout << encVals.first - startLeftEncVal << "  " << encVals.second - startRightEncVal
		     << "  (str: " << tics << ")" << endl;
		encVals = encodersModel.getChassisEncodersValues();

		if (encVals.first - startLeftEncVal > tics) {
			leftChassisMotor.setPower(0);
			leftMotorEnd = true;
			Helpers::dump(Helpers::Warning, "straight - leftMotorEnd");
		}

		if (encVals.second - startRightEncVal > tics) {
			rightChassisMotor.setPower(0);
			rightMotorEnd = true;
			Helpers::dump(Helpers::Warning, "straight - rightMotorEnd");
		}
	} while (!leftMotorEnd || !rightMotorEnd);

	cout << leftMotorEnd << "  " << rightMotorEnd << endl;

}