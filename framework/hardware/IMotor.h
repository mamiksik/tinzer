//
// Created by Martin Mikšík on 21/04/16.
//

#ifndef KETCHUPHOUSE_IENGINE_H
#define KETCHUPHOUSE_IENGINE_H

class IMotor
{
public:
	IMotor()
	{ }

	virtual ~IMotor()
	{ }

	//Set power to motor in range of 0 to 100
	virtual void setPower(int power) = 0;
};

#endif //KETCHUPHOUSE_IENGINE_H
