//
// Created by Renata
//

#ifndef KETCHUPHOUSE_BUTTON_H
#define KETCHUPHOUSE_BUTTON_H


#include "../ev3dev.h"
#include "../../../framework/hardware/IButton.h"

using ev3dev::address_type;
using namespace Interfaces::Hardware;

namespace Hardware {
	class Button : public IButton
	{
	public:

		Button(address_type motor_pin) : button(motor_pin)
		{}

		virtual bool isPressed();

	private:
		ev3dev::touch_sensor button;

	};
}
#endif //KETCHUPHOUSE_BUTTON_H
