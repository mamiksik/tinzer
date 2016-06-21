//
// Created by Martin Mikšík
//

#ifndef KETCHUPHOUSE_LOGICTHREAD_H
#define KETCHUPHOUSE_LOGICTHREAD_H

#include <iostream>
#include <thread>
#include <chrono>
#include <signal.h>
#include <csignal>

#include "../Config.h"
#include "../../framework/Helpers/Helpers.h"
#include "../hardware/motor/Motor.h"
#include "../hardware/encoder/Encoder.h"
#include "../hardware/button/Button.h"
#include "sensors/encoder/EncodersSensor.h"
#include "sensors/buttons/ButtonsSensor.h"
#include "controllers/motors/MotorController.h"
#include "BrainThread.h"

class Boostrap
{
public:
	void init()
	{
		std::signal(SIGABRT, teardown);
		std::signal(SIGFPE, teardown);
		std::signal(SIGILL, teardown);
		std::signal(SIGINT, teardown);
		std::signal(SIGSEGV, teardown);
		std::signal(SIGTERM, teardown);

		//Helpers::dump(Helpers::Warning, "Call with %d variable argument.", 1);

		using ev3dev::OUTPUT_A;
		using ev3dev::OUTPUT_B;

		using ev3dev::INPUT_1;

		Button stopButton(INPUT_1);

		Helpers::dump(Helpers::Info, "Init motors");
		Motor leftMotor(OUTPUT_A);
		Motor rightMotor(OUTPUT_B);

		Helpers::dump(Helpers::Info, "Init encoders");
		Encoder leftEncoder(OUTPUT_A);
		Encoder rightEncoder(OUTPUT_B);

		//Reset encoders
		Helpers::dump(Helpers::Warning, "Encoder manual reset");
		leftEncoder.set(0);
		rightEncoder.set(0);

		//Init model layer
		EncodersSensor encodersSensor(leftEncoder, rightEncoder);
		ButtonsSensor buttonSensor(stopButton);

		//Init controllers layer
		MotorController motorControl(leftMotor, rightMotor, encodersSensor,
		                             Coordinate(DEFAULT_X_POSITION, DEFAULT_Y_POSITION, DEFAULT_ROTATION), 40);


		//Init main controller
		BrainThread brainThread(motorControl);

		try {
			brainThread.startThread();

			while (true) {
				if (buttonSensor.getStopButton()) {
					throw std::runtime_error("Stop button pressed");
				}
			}

		} catch (...) {
			brainThread.stopThread();
		}

		teardown(-1);
	}


	static void teardown(int signal)
	{
		try {
			ev3dev::motor motor(ev3dev::OUTPUT_A);
			motor.set_command(ev3dev::motor::command_reset);
		}
		catch (...) {}

		try {
			ev3dev::motor motor(ev3dev::OUTPUT_B);
			motor.set_command(ev3dev::motor::command_reset);
		}
		catch (...) {}

		try {
			ev3dev::motor motor(ev3dev::OUTPUT_C);
			motor.set_command(ev3dev::motor::command_reset);
		}
		catch (...) {}

		try {
			ev3dev::motor motor(ev3dev::OUTPUT_D);
			motor.set_command(ev3dev::motor::command_reset);
		}
		catch (...) {}

		if (signal != -1 && signal != SIGINT) {
			std::cerr << "Program failed! Signal " << signal << " caught. Terminating" << std::endl;
			exit(1);
		}
		if (signal == SIGINT) {
			std::cerr << "Program stopped (probably CTR+C or StopButton)\n";
			exit(1);
		}
	}

};

#endif //KETCHUPHOUSE_LOGICTHREAD_H