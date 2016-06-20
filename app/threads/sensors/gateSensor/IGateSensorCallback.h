//
// Created by Martin Mikšík
//

#ifndef KETCHUPHOUSE_ICOLORSENSORCALLBACK_H
#define KETCHUPHOUSE_ICOLORSENSORCALLBACK_H

class IGateSensorCallback
{
public:
	virtual ~IGateSensorCallback()
	{}

	virtual void gatePenetrated() = 0;
};

#endif //KETCHUPHOUSE_ICOLORSENSORCALLBACK_H
