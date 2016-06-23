//
// Created by Martin Mikšík
//

#ifndef KETCHUPHOUSE_IDIODE_H
#define KETCHUPHOUSE_IDIODE_H

class IDiode
{
public:
	virtual ~IDiode()
	{}

	virtual void switchOn() = 0;

	virtual void switchOff() = 0;

	virtual void setIntensity() = 0;
};

#endif //KETCHUPHOUSE_IDIODE_H
