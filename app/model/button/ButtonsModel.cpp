//
// Created by Renata
//

#include <stdexcept>
#include "ButtonsModel.h"

bool ButtonsModel::isPressedStop()
{
	return stopButton.isPressed();
}

bool ButtonsModel::isPressedStart()
{
	return startButton.isPressed();
}
