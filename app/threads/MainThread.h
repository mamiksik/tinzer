//
// Created by Martin Mikšík
//

#ifndef KETCHUPHOUSE_LOGICTHREAD_H
#define KETCHUPHOUSE_LOGICTHREAD_H

#include <iostream>
#include <thread>
#include <chrono>

#include "../Config.h"
#include "../hardware/motor/Motor.h"
#include "../hardware/encoder/Encoder.h"
#include "../threads/sensors/EncoderSensor.h"
#include "controls/MotorControl.h"
#include "../../framework/Log.h"
#include "../hardware/motor/Motor.h"
#include "../hardware/encoder/Encoder.h"

class MainThread
{
public:
	void operator()()
	{
		using ev3dev::OUTPUT_A;
		using ev3dev::OUTPUT_B;

		//Log::dump(Log::All, "Creating motors");
		Motor leftMotor(OUTPUT_A);
		Motor rightMotor(OUTPUT_B);

		//cout << "Creating encoders" << endl;
		Encoder leftEncoder(OUTPUT_A, LEFT_ENCODER_FIX);
		Encoder rightEncoder(OUTPUT_B, RIGHT_ENCODER_FIX);

		cout << "Encoders created" << endl;
		cout << leftEncoder.getRelPosition() << endl;

		//Reset encoders
		leftEncoder.set(0);
		rightEncoder.set(0);

		cout << "Creating motorControl" << endl;
		MotorControl motorControl(leftMotor, rightMotor,
		                          Coordinate(DEFAULT_ROTATION, DEFAULT_X_POSITION, DEFAULT_Y_POSITION));

		vector<IEncoderCallback *> callbacks = {
				&motorControl
		};

		cout << "Creating encoderSensore" << endl;
		EncoderSensor encoderSensor(leftEncoder, rightEncoder, callbacks);

		cout << "Pushing coordinates" << endl;
		motorControl.push(Coordinate(0, 3, 10));
		//motorControl.push(Coordinate(M_PI, 0, 10));

		std::this_thread::sleep_for(std::chrono::milliseconds(1000));

		cout << "starting control run thread" << endl;
		motorControl.startRunThread();

		cout << "starting encoder run thread" << endl;
		encoderSensor.startRunThread();

		//motorControl.push(Coordinate(DEFAULT_ROTATION, 8, 1));

		//cout << "Pushing coordinates" << endl;
		//motorControl.push(Coordinate(DEFAULT_ROTATION, 0, 1));


	}
};

#endif //KETCHUPHOUSE_LOGICTHREAD_H