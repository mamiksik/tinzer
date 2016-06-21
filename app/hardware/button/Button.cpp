//
// Created by Renata
//

#include "Button.h"

bool Hardware::Button::isPressed()
{
	return button.is_pressed();
}
