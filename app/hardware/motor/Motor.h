//
// Created by Martin Mikšík
//

#ifndef KETCHUPHOUSE_MOTOR_H
#define KETCHUPHOUSE_MOTOR_H

#include "../../../framework/hardware/IMotor.h"
#include "../ev3dev.h"

using ev3dev::address_type;


class Motor : public IMotor
{
public:

	Motor(address_type motor_pin) : motor(motor_pin)
	{
		openedMotors.push_back(this);
	}


	virtual ~Motor()
	{
		auto last = std::remove_if(openedMotors.begin(), openedMotors.end(), [&](Motor *m) { return m == this; });
		openedMotors.erase(last, openedMotors.end());
	}


	static bool lock;

	void setPower(int power);

	static const std::vector<Motor *> get_motors();

private:
	ev3dev::motor motor;
	static std::vector<Motor *> openedMotors;
};


#endif //KETCHUPHOUSE_MOTOR_H
