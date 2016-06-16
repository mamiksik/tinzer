//
// Created by Martin Mikšík
//

#ifndef KETCHUPHOUSE_THREADING_H
#define KETCHUPHOUSE_THREADING_H


#include <thread>

class Threading
{
public:
	Threading() : repeatTask(true)
	{}

	virtual ~Threading()
	{
		stopThread();
	}

	void startThread();

	void stopThread();

protected:
	bool repeatTask;
	std::thread thread;

	virtual void threadTask() = 0;
};


#endif //KETCHUPHOUSE_THREADING_H
