//
// Created by Martin Mikšík on 25/04/16.
//

//#ifndef KETCHUPHOUSE_ENCODER_H
//#define KETCHUPHOUSE_ENCODER_H

#include "../ev3dev.h"
#include "../../threads/sensors/IEncoder.h"

using ev3dev::address_type;

class FakeEncoder : public IEncoder
{
public:
	virtual int getRelPosition()
	{
		return std::rand();
	}
};


//#endif //KETCHUPHOUSE_ENCODER_H
