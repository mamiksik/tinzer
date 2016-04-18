//
// Created by Martin Mikšík
//

#ifndef KETCHUPHOUSE_INSTRUCTION_H
#define KETCHUPHOUSE_INSTRUCTION_H
namespace structure {
	struct Instruction
	{
		Instruction(int engine, double distance, int power) : engine(engine), distance(distance), power(power)
		{ }

		int engine;
		double distance;
		int power;
	};
}
#endif //KETCHUPHOUSE_INSTRUCTION_H
