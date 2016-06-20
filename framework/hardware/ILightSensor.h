//
// Created by Martin Mikšík
//

#ifndef KETCHUPHOUSE_ICOLORSENSOR_H
#define KETCHUPHOUSE_ICOLORSENSOR_H


class ILightSensor
{
public:
	virtual ~ILightSensor()
	{}

	virtual int getAmbient() = 0;
};


#endif //KETCHUPHOUSE_ICOLORSENSOR_H
