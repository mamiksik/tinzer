//
// Created by Martin Mikšík
//

#ifndef KETCHUPHOUSE_INSTRUCTION_H
#define KETCHUPHOUSE_INSTRUCTION_H

struct Instruction
{
	Instruction(bool action, double distance, int power) : action(action), distance(distance), power(power)
	{ }

	//1 = move forward 0 = turn
	bool action;
	double distance;
	int power;
};

#endif //KETCHUPHOUSE_INSTRUCTION_H
