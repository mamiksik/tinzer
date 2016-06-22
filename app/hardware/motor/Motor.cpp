//
// Created by Martin Mikšík on 12/03/16.
//

#include "Motor.h"
#include <stdexcept>
#include <stdlib.h>
void Motor::setPower(int power)
{
	if (power < -100 || power > 100) {
		throw std::runtime_error("Power out of range: " + std::to_string(abs(power)) + "/100");
	}

	if (motor.speed_regulation_enabled() == "on") {
		motor.set_speed_regulation_enabled("off");
	}

	motor.set_duty_cycle_sp(power);
	motor.run_forever();
}
