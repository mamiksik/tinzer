//
// Created by Martin Mikšík
//

#ifndef KETCHUPHOUSE_INSTRUCTION_H
#define KETCHUPHOUSE_INSTRUCTION_H
namespace structure {
	struct Instruction
	{
		Instruction(double tics, int power) : tics(tics), power(power)
		{}

		double tics;
		int power;
	};
}
#endif //KETCHUPHOUSE_INSTRUCTION_H
