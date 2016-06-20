//
// Created by Martin Mikšík
//

#ifndef KETCHUPHOUSE_IULTRASONICSENSOR_H
#define KETCHUPHOUSE_IULTRASONICSENSOR_H

class IUltrasonicSensor
{
public:
	virtual void enable() = 0;

	virtual void disable() = 0;

	virtual double getDistanceInCm() = 0;
};

#endif //KETCHUPHOUSE_IULTRASONICSENSOR_H
