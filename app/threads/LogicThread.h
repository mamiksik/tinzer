//
// Created by Martin Mikšík
//

#ifndef KETCHUPHOUSE_LOGICTHREAD_H
#define KETCHUPHOUSE_LOGICTHREAD_H

#include <iostream>
#include <thread>
#include <chrono>

#include "../Config.h"
//#include "../hardware/motor/FakeMotor.h"
//#include "../hardware/encoder/FakeEncoder.h"
#include "../hardware/motor/Motor.h"
#include "../hardware/encoder/Encoder.h"
#include "../threads/sensors/EncoderSensor.h"
#include "controls/MotorControl.h"

class LogicThread
{
public:
	void operator()()
	{
		using ev3dev::OUTPUT_A;
		using ev3dev::OUTPUT_B;

		cout << "Creating motors" << endl;
		Motor leftMotor(OUTPUT_A);
		Motor rightMotor(OUTPUT_B);

		//FakeMotor leftMotor;
		//FakeMotor rightMotor;
		cout << "Motors created" << endl;

		cout << "Creating encoders" << endl;
		Encoder leftEncoder(OUTPUT_A);
		Encoder rightEncoder(OUTPUT_B);

		//FakeEncoder leftEncoder;
		//FakeEncoder rightEncoder;
		cout << "Encoders created" << endl;

		//Reset encoders

		cout << "Creating motorControl" << endl;
		MotorControl motorControl(leftMotor, rightMotor,
		                          Coordinate(DEFAULT_ROTATION, DEFAULT_X_POSITION, DEFAULT_Y_POSITION));

		vector<IEncoderCallback *> callbacks = {
				&motorControl
		};

		cout << "Creating encoderSensore" << endl;
		EncoderSensor encoderSensor(leftEncoder, rightEncoder, callbacks);

		cout << "Pushing coordinates" << endl;
		motorControl.push(Coordinate(M_PI, 5, 15));
		motorControl.push(Coordinate(M_PI, 0, 15));

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