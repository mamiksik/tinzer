//
// Created by Renatas
//

#ifndef KETCHUPHOUSE_BUTTONSENSOR_H
#define KETCHUPHOUSE_BUTTONSENSOR_H

#include <iostream>
#include <vector>
#include <thread>
#include "../../../../framework/hardware/IButton.h"
#include "../../../../framework/threading/Threading.h"

using namespace std;

class StopButtonSensor : public Threading
{
public:
	StopButtonSensor(IButton &button) : button(button)
	{}

	virtual ~StopButtonSensor()
	{
		stopThread();
	}

private:
	IButton &button;

	virtual void threadTask();
};

#endif //KETCHUPHOUSE_BUTTONSENSOR_H
