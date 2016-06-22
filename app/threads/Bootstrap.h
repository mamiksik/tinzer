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
#include "../hardware/ultrasonicSensor/UltrasonicSensor.h"

#include "../model/encoder/EncodersModel.h"
#include "../model/button/ButtonsModel.h"

#include "controller/Controller.h"
#include "logic/Logic.h"
#include "../model/line/LineModel.h"


using namespace Hardware;
using namespace Model;

class Bootstrap
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

		using ev3dev::OUTPUT_A;
		using ev3dev::OUTPUT_B;
		using ev3dev::OUTPUT_C;
		using ev3dev::OUTPUT_D;

		using ev3dev::INPUT_1;
		using ev3dev::INPUT_2;

		Button stopButton(INPUT_1);

		Helpers::dump(Helpers::Debug, "Init motors");
		/*Motor leftChassisMotor(OUTPUT_C);
		Motor rightChassisMotor(OUTPUT_D);*/
/*
		Motor leftGateMotor(OUTPUT_A);
		Motor rightGateMotor(OUTPUT_B);

		Helpers::dump(Helpers::Debug, "Init encoders");
		Encoder leftChassisEncoder(OUTPUT_C);
		Encoder rightChassisEncoder(OUTPUT_D);

		Encoder leftGateEncoder(OUTPUT_A);
		Encoder rightGateEncoder(OUTPUT_B);

			Helpers::dump(Helpers::Debug, "Init ultrasonic");
			UltrasonicSensor gateUltrasonicSensor(INPUT_2, true);

			//Reset encoders
			Helpers::dump(Helpers::Warning, "Encoder manual reset");
			leftChassisEncoder.set(0);
			rightChassisEncoder.set(0);

			//Init model layer
			EncodersModel encodersSensor(leftChassisEncoder, rightChassisEncoder, leftGateEncoder, rightGateEncoder);
			ButtonsModel buttonSensor(stopButton);
			UltrasonicSensor ultrasonicSensor(gateUltrasonicSensor);
			LineModel lineModel;

			//Init controller layer
			Controller controller(Coordinate(DEFAULT_X_POSITION, DEFAULT_Y_POSITION, DEFAULT_ROTATION), 40,
									encodersSensor,
									lineModel,
									leftChassisMotor,
									rightChassisMotor,
									leftGateMotor,
									rightGateMotor);


			//Init main controller
			Logic logic(controller);*/

		ButtonsModel buttonSensor(stopButton);

		try {
			//logic.startThread();

			cout << "Running stop button" << endl;
			bool doWhile = true;

			while (doWhile) {
				if (buttonSensor.getStopButton()) {
					doWhile = false;
					throw std::runtime_error("Stop button pressed");
				}
			}

		} catch (...) {
			//logic.stopThread();
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