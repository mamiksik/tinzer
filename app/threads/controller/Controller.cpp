//
// Created by Martin Mikšík
//

#include <cmath>

#include "Controller.h"

void Controller::push(Coordinate newCoordinate)
{
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

	//TODO: First x or y
	//if (yRotation > xRotation) {
	if (currentCoordinate.rotation != xRotation) {
		stepQueue.push(Coordinate(currentCoordinate.x, currentCoordinate.y, xRotation));
		currentCoordinate.rotation = xRotation;
	}

	if (currentCoordinate.x != newCoordinate.x) {
		stepQueue.push(Coordinate(newCoordinate.x, currentCoordinate.y, xRotation));
		currentCoordinate.x = newCoordinate.x;
	}

	if (currentCoordinate.rotation != yRotation) {
		stepQueue.push(Coordinate(currentCoordinate.x, currentCoordinate.y, yRotation));
		currentCoordinate.rotation = yRotation;
	}

	if (currentCoordinate.y != newCoordinate.y) {
		stepQueue.push(Coordinate(currentCoordinate.x, newCoordinate.y, yRotation));
		currentCoordinate.y = newCoordinate.y;
	}
}

void Controller::threadTask()
{
	do {
		if (lock || stepQueue.empty()) {
			continue;
		}

		Coordinate newCoordinate = stepQueue.front();
		stepQueue.pop();

	} while (repeatTask);
}

