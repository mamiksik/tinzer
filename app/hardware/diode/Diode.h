//
// Created by Martin Mikšík
//

#ifndef KETCHUPHOUSE_DIODE_H
#define KETCHUPHOUSE_DIODE_H


#include "../ev3dev.h"
#include "../../../framework/hardware/IDiode.h"

using ev3dev::address_type;

class Diode : public IDiode
{
public:
	Diode(address_type sensorPort) : sensor(sensorPort)
	{}

	virtual void switchOn();

	virtual void switchOff();

	virtual void setIntensity();

private:
	ev3dev::color_sensor sensor;
};


#endif //KETCHUPHOUSE_DIODE_H
