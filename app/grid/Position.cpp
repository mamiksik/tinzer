//
// Created by Martin Mikšík
//

#include "Position.h"

void Position::moveToPosition(Coordinates coordinates)
{
	int leightOfLine = 90;

	int x = coordinates.x;
	int y = coordinates.y;

	if (x > sizeX) {
		throw "Position X cannot be higher than size of field";
	}

	if (y > sizeY) {
		throw "Position Y cannot be higher than size of field";
	}

	int newX = x * leightOfLine - current.x * leightOfLine;
	int newY = y * leightOfLine - current.y * leightOfLine;

	//control.calibrateRotation();

	if (newX > current.x) {

		switch (current.angle) {
			case 1:
				makeMove(Instruction(0, -0.25, turnPower));
				break;
			case 2:
				makeMove(Instruction(0, 0.5, turnPower));
				break;
			case 3:
				makeMove(Instruction(0, 0.25, turnPower));
				break;
		}
		current.angle = 0;
		current.x = x;
		makeMove(Instruction(1, newX, forwardPower));

	} else if (newX < current.x) {

		switch (current.angle) {
			case 0:
				makeMove(Instruction(0, 0.5, turnPower));
				break;
			case 1:
				makeMove(Instruction(0, 0.25, turnPower));
				break;
			case 3:
				makeMove(Instruction(0, -0.25, turnPower));
				break;
		}
		current.angle = 2;
		current.x = x;
		makeMove(Instruction(1, newX, forwardPower));
	}


	if (newY > current.y) {
		switch (current.angle) {
			case 0:
				makeMove(Instruction(0, 0.25, turnPower));
				break;
			case 2:
				makeMove(Instruction(0, -0.25, turnPower));
				break;
		}
		current.angle = 1;
		current.y = y;
		makeMove(Instruction(1, newY, forwardPower));
	} else if (newY < current.y) {
		switch (current.angle) {
			case 0:
				makeMove(Instruction(0, -0.25, turnPower));
				break;
			case 2:
				makeMove(Instruction(0, 0.25, turnPower));
				break;
		}
		current.angle = 3;
		current.y = y;
		makeMove(Instruction(1, newY, forwardPower));
	}
}

void Position::makeMove(Instruction instruction)
{
	mtx.lock();
	instructionsStack.push(instruction);
	mtx.unlock();
}

void Position::moveToHome(void)
{

}
