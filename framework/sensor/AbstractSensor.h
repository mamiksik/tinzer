//
// Created by Martin Mikšík
//

#ifndef KETCHUPHOUSE_ABSTRACTSENSORE_H
#define KETCHUPHOUSE_ABSTRACTSENSORE_H


#include <thread>

class AbstractSensor
{
public:
	AbstractSensor()
	{ }

	virtual ~AbstractSensor()
	{ }

	//std::thread threadRun();

protected:
	virtual void run() = 0;
};


#endif //KETCHUPHOUSE_ABSTRACTSENSORE_H
