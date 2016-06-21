//
// Created by Renata
//

#include <stdexcept>
#include "ButtonsModel.h"

bool Model::ButtonsModel::getStopButton()
{
	return stopButton.isPressed();
}
