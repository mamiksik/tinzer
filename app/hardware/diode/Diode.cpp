//
// Created by Martin Mikšík
//

#include "Diode.h"
#include "../../../framework/Helpers/Helpers.h"

void Diode::switchOn()
{
	sensor.set_mode(ev3dev::color_sensor::mode_col_reflect);

}

void Diode::switchOff()
{
	sensor.set_mode(ev3dev::color_sensor::mode_col_ambient);
}

void Diode::setIntensity()
{
	Helpers::dump(Helpers::Warning, "This diode does not support set intensity");
}
