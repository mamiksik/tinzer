//
// Created by Renata
//

#include <stdexcept>
#include "ButtonsModel.h"

bool ButtonsModel::getStopButton()
{
	return stopButton.isPressed();
}
