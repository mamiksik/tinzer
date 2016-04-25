//
// Created by Martin Mikšík
//

#ifndef KETCHUPHOUSE_LOGICTHREAD_H
#define KETCHUPHOUSE_LOGICTHREAD_H

#include <iostream>

#include "../Config.h"
#include "../hardware/motor/Motor.h"
#include "../hardware/encoder/Encoder.h"
#include "../threads/sensors/EncoderSensor.h"
#include "controls/MotorControl.h"

class LogicThread
{
public:
	void operator()()
	{

		/*using ev3dev::OUTPUT_A;
		using ev3dev::OUTPUT_B;

		Motor leftMotor(OUTPUT_A);
		Motor rightMotor(OUTPUT_B);

		Encoder leftEncoder(OUTPUT_A);
		Encoder rightEncoder(OUTPUT_B);*/

		/*MotorControl motorControl(leftMotor, rightMotor, Coordinate(0, 0, 1));

		vector<IEncoderCallback> callbacks = {
				motorControl
		};

		EncoderSensor encoderSensor(leftEncoder, rightEncoder, callbacks);*/
	}
};

#endif //KETCHUPHOUSE_LOGICTHREAD_H