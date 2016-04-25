//
// Created by Martin Mikšík
//

#ifndef KETCHUPHOUSE_INSTRUCTION_H
#define KETCHUPHOUSE_INSTRUCTION_H
namespace structure {
	struct Instruction
	{
		Instruction(double tic, int power) : tic(tic), power(power)
		{ }

		double tic;
		int power;
	};
}
#endif //KETCHUPHOUSE_INSTRUCTION_H
