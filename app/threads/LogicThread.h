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
		cout << "Motors created" << endl;


		leftMotor.setPower(50);
		rightMotor.setPower(50);
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));

		leftMotor.setPower(0);
		rightMotor.setPower(0);

		cout << "Creating encoders" << endl;
		Encoder leftEncoder(OUTPUT_A);
		Encoder rightEncoder(OUTPUT_B);
		cout << "Encoders created" << endl;

		cout << "Creating motorControl" << endl;
		MotorControl motorControl(leftMotor, rightMotor, Coordinate(0, 0, 1));

		vector<MotorControl> callbacks = {
				motorControl
		};

		cout << "Creating encoderSensore" << endl;
		EncoderSensor encoderSensor(leftEncoder, rightEncoder, callbacks);


		cout << "Pushing coordinates" << endl;
		motorControl.push(Coordinate(4, 8, 1));


		cout << "starting control run thread" << endl;
		thread motorControlRun = motorControl.threadRun();

		cout << "starting encoder run thread" << endl;
		thread encoderSensorRun = encoderSensor.threadRun();


		cout << "Pushing coordinates" << endl;
		motorControl.push(Coordinate(2, 5, 1));


		motorControlRun.join();
		encoderSensorRun.join();

		cout << "Test" << endl;

	}
};

#endif //KETCHUPHOUSE_LOGICTHREAD_H