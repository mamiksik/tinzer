//
// Created by Martin Mikšík
//

#include <thread>
#include "EncoderSync.h"
#include "../Helpers.h"

void EncoderSync::sync()
{
	leftEncoder.set(0);
	rightEncoder.set(0);

	leftMotor.setPower(100);
	rightMotor.setPower(100);

	std::this_thread::sleep_for(std::chrono::milliseconds(100));

	leftMotor.setPower(0);
	rightMotor.setPower(0);

	leftEncoder.set(0);
	rightEncoder.set(0);

	int leftEncoderValue = leftEncoder.getAbsPosition();
	int rightEncoderValue = rightEncoder.getAbsPosition();

	/*//int diff = abs(leftEncoderValue - rightEncoderValue);

	if (leftEncoderValue > rightEncoderValue) {
		double fix = diff / leftEncoderValue;
		Log::dump(Log::All, "Right encoder fix is ", fix);

	} else {
		double fix = diff / rightEncoderValue;
		Log::dump(Log::All, "Left encoder fix is ", fix);
	}*/
}