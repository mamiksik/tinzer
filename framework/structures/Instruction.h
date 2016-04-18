//
// Created by Martin Mikšík
//

#ifndef KETCHUPHOUSE_INSTRUCTION_H
#define KETCHUPHOUSE_INSTRUCTION_H
namespace structure {
	struct Instruction
	{
		Instruction(double distance, int power) : distance(distance), power(power)
		{ }

		double distance;
		int power;
	};
}
#endif //KETCHUPHOUSE_INSTRUCTION_H
