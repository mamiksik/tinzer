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
	{
		stopThread = false;
	}

	virtual ~AbstractSensor()
	{
		stopThread = true;
		if (runThread.joinable()) {
			runThread.join();
		}
	}

	void startRunThread();

	void stopRunThread();

protected:
	bool stopThread;
	std::thread runThread;

	virtual void run() = 0;
};


#endif //KETCHUPHOUSE_ABSTRACTSENSORE_H
