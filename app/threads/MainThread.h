//
// Created by Martin Mikšík
//

#ifndef KETCHUPHOUSE_LOGICTHREAD_H
#define KETCHUPHOUSE_LOGICTHREAD_H

#include <iostream>
#include <thread>
#include <chrono>

#include "../Config.h"
#include "../../framework/Helpers/Helpers.h"
#include "../hardware/motor/Motor.h"
#include "../hardware/encoder/Encoder.h"
#include "../threads/sensors/EncoderSensor.h"
#include "controls/MotorControl.h"

class MainThread
{
public:
	void operator()()
	{
		//Helpers::dump(Helpers::Warning, "Call with %d variable argument.", 1);

		using ev3dev::OUTPUT_A;
		using ev3dev::OUTPUT_B;

		Helpers::dump(Helpers::Info, "Init motors");
		Motor leftMotor(OUTPUT_A);
		Motor rightMotor(OUTPUT_B);

		//FakeMotor leftMotor;
		//FakeMotor rightMotor;

		Helpers::dump(Helpers::Info, "Init encoders");
		Encoder leftEncoder(OUTPUT_A);
		Encoder rightEncoder(OUTPUT_B);

		//FakeEncoder leftEncoder;
		//FakeEncoder rightEncoder;

		//Reset encoders
		Helpers::dump(Helpers::Warning, "Encoder manual reset");
		leftEncoder.set(0);
		rightEncoder.set(0);

		MotorControl motorControl(leftMotor,
		                          rightMotor,
		                          Coordinate(DEFAULT_ROTATION, DEFAULT_X_POSITION, DEFAULT_Y_POSITION));

		vector<IEncoderCallback *> callbacks = {
				&motorControl
		};

		EncoderSensor encoderSensor(leftEncoder, rightEncoder, callbacks);

		Helpers::dump(Helpers::Debug, "Pushing coordinates [0, 2, 2]");
		//motorControl.push(Coordinate(0, 2, 2));


		cout << "starting control run thread" << endl;
		motorControl.startThread();

		cout << "starting encoder run thread" << endl;
		encoderSensor.startThread();

		motorControl.push(Coordinate(3, 3, M_PI_2));
		motorControl.push(Coordinate(-3, 1, M_PI_2));

		bool keepGoing = true;

		while (keepGoing) {
			keepGoing = true;
		}

	}
};

#endif //KETCHUPHOUSE_LOGICTHREAD_H