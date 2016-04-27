//
// Created by Martin Mikšík on 20/04/16.
//

#ifndef KETCHUPHOUSE_IENCODERSENSORE_H
#define KETCHUPHOUSE_IENCODERSENSORE_H

class IEncoderCallback
{
public:
	IEncoderCallback()
	{ }

	virtual ~IEncoderCallback()
	{ }

	virtual void encoderProcess(int leftEncoder, int rightEncoder) = 0;
};

#endif //KETCHUPHOUSE_IENCODERSENSORE_H
