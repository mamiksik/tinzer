//
// Created by Renatas
//

#ifndef KETCHUPHOUSE_BUTTONSENSOR_H
#define KETCHUPHOUSE_BUTTONSENSOR_H

#include <iostream>
#include <vector>
#include <thread>
#include "../../../framework/hardware/IButton.h"
#include "../../../framework/threading/Threading.h"

using namespace std;


class ButtonsModel
{
public:
	ButtonsModel(IButton &stopButton) : stopButton(stopButton)
	{}

	bool getStopButton();

private:
	IButton &stopButton;
};


#endif //KETCHUPHOUSE_BUTTONSENSOR_H
