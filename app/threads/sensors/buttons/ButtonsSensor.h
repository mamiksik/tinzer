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

class ButtonsSensor
{
public:
	ButtonsSensor(IButton &stopButtom) : stopButton(stopButtom)
	{}

	bool getStopButton();

private:
	IButton &stopButton;
};

#endif //KETCHUPHOUSE_BUTTONSENSOR_H
