//
// Created by Martin Mikšík on 25/04/16.
//

#ifndef KETCHUPHOUSE_IENCODER_H
#define KETCHUPHOUSE_IENCODER_H

class IEncoder
{
public:

	IEncoder()
	{ }

	virtual ~IEncoder()
	{ }

	virtual int getAbsPosition() = 0;

	virtual void set(int position) = 0;
};

#endif //KETCHUPHOUSE_IENCODER_H
