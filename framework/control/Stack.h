//
// Created by Martin Mikšík on 13/04/16.
//

#ifndef KETCHUPHOUSE_STACK_H
#define KETCHUPHOUSE_STACK_H


class Stack
{
public:
	void push();

	void pause();

	bool isEmpty();

	bool isReady();

	void aboard();

	auto getPosition(); // universality?
};


#endif //KETCHUPHOUSE_STACK_H
