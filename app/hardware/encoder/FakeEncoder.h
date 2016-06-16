//
// Created by Martin Mikšík
//

#ifndef KETCHUPHOUSE_FAKEENCODER_H
#define KETCHUPHOUSE_FAKEENCODER_H

#include <iostream>
#include "../../../framework/hardware/IEncoder.h"

class FakeEncoder : public IEncoder
{
public:
	FakeEncoder()
	{}

	virtual int getAbsPosition()
	{
		position += 1;
		return position;
	};

	virtual void set(int position)
	{
		position = 0;
	};

private:
	int position;
};


#endif //KETCHUPHOUSE_FAKEENCODER_H
