//
// Created by Martin Mikšík on 25/04/16.
//

#ifndef KETCHUPHOUSE_FAKE_ENCODER_H
#define KETCHUPHOUSE_FAKE_ENCODER_H

#include "../ev3dev.h"
#include "../../../framework/hardware/IEncoder.h"

using ev3dev::address_type;

class FakeEncoder : public IEncoder
{
public:
	virtual int getRelPosition()
	{
		return std::rand();
	}

	virtual void set(int position)
	{

	}
};

#endif //KETCHUPHOUSE_FAKE_ENCODER_H
