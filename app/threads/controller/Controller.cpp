//
// Created by Martin Mikšík
//

#include <cmath>

#include "Controller.h"

bool Controller::lockMotors = false;


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
	if (expectedCoordinate.x != newCoordinate.x) {

		if (expectedCoordinate.rotation != xRotation) {
			stepQueue.push(Coordinate(expectedCoordinate.x, expectedCoordinate.y, xRotation));
			expectedCoordinate.rotation = xRotation;
		}

		stepQueue.push(Coordinate(newCoordinate.x, expectedCoordinate.y, xRotation));
		expectedCoordinate.x = newCoordinate.x;
	}


	if (expectedCoordinate.y != newCoordinate.y) {

		if (expectedCoordinate.rotation != yRotation) {
			stepQueue.push(Coordinate(expectedCoordinate.x, expectedCoordinate.y, yRotation));
			expectedCoordinate.rotation = yRotation;
		}
		stepQueue.push(Coordinate(expectedCoordinate.x, newCoordinate.y, yRotation));
		expectedCoordinate.y = newCoordinate.y;
	}

	if (expectedCoordinate.rotation != newCoordinate.rotation) {
		stepQueue.push(Coordinate(expectedCoordinate.x, expectedCoordinate.y, newCoordinate.rotation));
		expectedCoordinate.rotation = newCoordinate.rotation;
	}
}


void Controller::closeGates()
{
	// down RIGHT = + LEFT = -
	// up RIGHT = - LEFT = +

	pair<int, int> encVals = encodersModel.getGateEncodersValues();

	int startLeftEncVal = encVals.first;
	int startRightEncVal = encVals.second;

	bool leftMotorEnd = false;
	bool rightMotorEnd = false;

	if (leftGateOpen) {
		leftGateMotor.setPower(-GATE_POWER);
	} else {
		Helpers::dump(Helpers::Error, "Left gate closed");
		leftMotorEnd = true;
	}

	if (rightGateOpen) {
		rightGateMotor.setPower(GATE_POWER);
	} else {
		Helpers::dump(Helpers::Error, "Right gate closed");
		rightMotorEnd = true;
	}

	do {

		encVals = encodersModel.getGateEncodersValues();

		if (encVals.first - startLeftEncVal <= -GATE_TICS) {
			leftGateMotor.setPower(0);
			leftMotorEnd = true;
		}

		if (encVals.second - startRightEncVal >= GATE_TICS) {
			rightGateMotor.setPower(0);
			rightMotorEnd = true;
		}
	} while (!leftMotorEnd || !rightMotorEnd);

	leftGateOpen = false;
	rightGateOpen = false;
}


void Controller::openLeftGate()
{
	if (leftGateOpen) {
		Helpers::dump(Helpers::Error, "Left gate opend");
		return;
	}

	Helpers::dump(Helpers::Info, "Opening left gate");
	int encVal = encodersModel.getLeftGateEncodersValue();
	int startEncVal = encVal;
	bool stop = false;

	leftGateMotor.setPower(GATE_POWER);

	do {
		encVal = encodersModel.getLeftGateEncodersValue();

		if (encVal - startEncVal >= GATE_TICS) {
			leftGateMotor.setPower(0);
			stop = true;
		}

	} while (!stop);

	leftGateOpen = true;
}


void Controller::openRightGate()
{
	if (rightGateOpen) {
		Helpers::dump(Helpers::Error, "Right gate opend");
		return;
	}

	Helpers::dump(Helpers::Warning, "Opening right gate");
	int encVal = encodersModel.getRightGateEncodersValue();
	int startEncVal = encVal;
	bool stop = false;

	rightGateMotor.setPower(-GATE_POWER);

	do {
		encVal = encodersModel.getRightGateEncodersValue();

		if (encVal - startEncVal <= -GATE_TICS) {
			rightGateMotor.setPower(0);
			stop = true;
		}

	} while (!stop);

	rightGateOpen = true;
}


void Controller::threadTask()
{
	do {
		if (lockStack || stepQueue.empty()) {
			//Helpers::dump(Helpers::Debug, "eempty");
			Helpers::delay(1);
			continue;
		}

		//array<int, 3> correctionVals = lineModel.getCorectionData();
		array<double, 3> correctionVals;

		correctionVals[0] = 100;
		correctionVals[1] = 100;
		correctionVals[2] = 0;

		Coordinate newCoordinate = stepQueue.front();
		stepQueue.pop();

		Helpers::dump(Helpers::Debug, "thread task");
		cout << "Thread task coordinates X: " << newCoordinate.x << " Y: " << newCoordinate.y << " Rot: "
		     << newCoordinate.rotation << endl;
		//Helpers::delay(2000);

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
			directionX dirX = witchDirectionInX(currentCoordinate.x, newCoordinate.x);

			if (dirX == directionX::right) {
				//x = LINE_LEIGHT - correctionVals[0];
				x = (abs(currentCoordinate.x - newCoordinate.x) * LINE_LEIGHT) - correctionVals[0];
			} else {
				//x = LINE_LEIGHT + correctionVals[0];
				x = (abs(currentCoordinate.x - newCoordinate.x) * LINE_LEIGHT) + correctionVals[0];
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
			doRotation(alpha);

			cout << "c: " << c << endl;
			goStraight(static_cast<int>(c));
			currentCoordinate.x = newCoordinate.x;
		}

		if (currentCoordinate.y != newCoordinate.y) {
			int y = 0;
			directionY dirY = witchDirectionInY(currentCoordinate.y, newCoordinate.y);

			if (dirY == directionY::up) {
				//y = LINE_LEIGHT - correctionVals[1];
				y = (abs(currentCoordinate.y - newCoordinate.y) * LINE_LEIGHT) - correctionVals[1];
			} else {
				//y = LINE_LEIGHT + correctionVals[1];
				y = (abs(currentCoordinate.y - newCoordinate.y) * LINE_LEIGHT) + correctionVals[1];

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
			currentCoordinate.y = newCoordinate.y;
		}
		Helpers::delay(1);
		repeatTask = true;
	} while (repeatTask);
}


Coordinate Controller::getPosition()
{
	return currentCoordinate;
}


void Controller::unload()
{
	Helpers::dump(Helpers::Info, "Unloading stacks");
	openLeftGate();
	//TODO: Dont use const val
	int tics = static_cast<int>(ENCODER_RESOLUTION * 2 * LINE_LEIGHT / (WHEEL_DIAMETER * M_PI));

	pair<int, int> encVals = encodersModel.getChassisEncodersValues();
	int startLeftEncVal = encVals.first;
	int startRightEncVal = encVals.second;

	bool leftMotorEnd = false;
	bool rightMotorEnd = false;

	leftChassisMotor.setPower(-power);
	rightChassisMotor.setPower(-power);

	do {
		encVals = encodersModel.getChassisEncodersValues();

		Helpers::dump(Helpers::Warning, "Do unload");

		if (encVals.first - startLeftEncVal <= -tics) {
			leftChassisMotor.setPower(0);
			leftMotorEnd = true;
			Helpers::dump(Helpers::Warning, "straight - leftMotorEnd");
		}

		if (encVals.second - startRightEncVal <= -tics) {
			rightChassisMotor.setPower(0);
			rightMotorEnd = true;
			Helpers::dump(Helpers::Warning, "straight - rightMotorEnd");
		}

		if (encVals.second - startRightEncVal <= -tics / 2 || encVals.first - startLeftEncVal <= -tics / 2) {
			openRightGate();
		}

		Helpers::delay(1);
	} while (!leftMotorEnd || !rightMotorEnd);

	currentCoordinate.x = 2;
	currentCoordinate.y = 0;
	currentCoordinate.rotation = M_PI;
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
			encVals = encodersModel.getChassisEncodersValues();

			if (lockMotors) {
				leftChassisMotor.setPower(0);
				rightChassisMotor.setPower(0);
				continue;
			} else {
				leftChassisMotor.setPower(-power);
				rightChassisMotor.setPower(power);
			}

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
			Helpers::delay(1);
		} while (!leftMotorEnd || !rightMotorEnd);

	} else {
		leftChassisMotor.setPower(power);
		rightChassisMotor.setPower(-power);

		do {
			encVals = encodersModel.getChassisEncodersValues();

			if (lockMotors) {
				leftChassisMotor.setPower(0);
				rightChassisMotor.setPower(0);
				continue;
			} else {
				leftChassisMotor.setPower(power);
				rightChassisMotor.setPower(-power);
			}

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
			Helpers::delay(1);
		} while (!leftMotorEnd || !rightMotorEnd);
	}
}


Controller::directionX Controller::witchDirectionInX(int currentX, int newX)
{
	if (currentX < newX) {
		return directionX::right;
	} else if (currentX > newX) {
		return directionX::left;
	} else {
		return directionX::none;
	}
}


Controller::directionY Controller::witchDirectionInY(int currentY, int newY)
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
		encVals = encodersModel.getChassisEncodersValues();

		if (lockMotors) {
			leftChassisMotor.setPower(0);
			rightChassisMotor.setPower(0);
			continue;
		} else {
			leftChassisMotor.setPower(power);
			rightChassisMotor.setPower(power);
		}

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
		Helpers::delay(1);
	} while (!leftMotorEnd || !rightMotorEnd);

	cout << leftMotorEnd << "  " << rightMotorEnd << endl;

}


void Controller::setPower(int power)
{
	Controller::power = power;
}


int Controller::getPower() const
{
	return power;
}
