//
// Created by Martin Mikšík
//

#ifndef KETCHUPHOUSE_LOGICTHREAD_H
#define KETCHUPHOUSE_LOGICTHREAD_H

#include <iostream>
#include <thread>
#include <chrono>
#include <csignal>

#include "../Config.h"
#include "../../framework/Helpers/Helpers.h"

#include "../hardware/motor/Motor.h"
#include "../hardware/encoder/Encoder.h"
#include "../hardware/button/Button.h"
#include "../hardware/ultrasonicSensor/Ultrasonic.h"

#include "../model/encoder/EncodersModel.h"
#include "../model/button/ButtonsModel.h"

#include "controller/Controller.h"
#include "logic/Logic.h"
#include "../model/line/LineModel.h"
#include "../model/ultrasonic/UltrasonicModel.h"
#include "../hardware/diode/Diode.h"
#include "../hardware/reflectiveBar/ReflectiveBar.h"

class Bootstrap
{
public:
	void init()
	{
		std::signal(SIGABRT, Bootstrap::teardown);
		std::signal(SIGFPE, Bootstrap::teardown);
		std::signal(SIGILL, Bootstrap::teardown);
		std::signal(SIGINT, Bootstrap::teardown);
		std::signal(SIGSEGV, Bootstrap::teardown);
		std::signal(SIGTERM, Bootstrap::teardown);

		using ev3dev::OUTPUT_A;
		using ev3dev::OUTPUT_B;
		using ev3dev::OUTPUT_C;
		using ev3dev::OUTPUT_D;

		using ev3dev::INPUT_1;
		using ev3dev::INPUT_2;
		using ev3dev::INPUT_3;

		using ev3dev::INPUT_4;

		Button stopButton(INPUT_1);

		Button startButton(INPUT_4);


		Diode gateDiode(INPUT_3);

		Helpers::dump(Helpers::Debug, "Init motors");
		Motor leftChassisMotor(OUTPUT_C);
		Motor rightChassisMotor(OUTPUT_D);

		Motor leftGateMotor(OUTPUT_A);
		Motor rightGateMotor(OUTPUT_B);

		Helpers::dump(Helpers::Debug, "Init encoders");
		Encoder leftChassisEncoder(OUTPUT_D);
		Encoder rightChassisEncoder(OUTPUT_C);

		Encoder leftGateEncoder(OUTPUT_A);
		Encoder rightGateEncoder(OUTPUT_B);

		Helpers::dump(Helpers::Debug, "Init ultrasonic");
		Ultrasonic gateUltrasonicSensor(INPUT_2, false);


		//Reflective bars
		//ReflectiveBar leftReflectiveBar("/ttcy/ACM", "nic_neposilej");
		//ReflectiveBar rightReflectiveBar("/ttcy/ACM", "nic_neposilej");
		//ReflectiveBar bottomReflectiveBar("/ttcy/ACM", "nic_neposilej");

		//Reset encoders
		Helpers::dump(Helpers::Warning, "Encoder manual reset");
		leftChassisEncoder.set(0);
		rightChassisEncoder.set(0);
		leftGateEncoder.set(0);
		rightGateEncoder.set(0);

		//Init model layer
		EncodersModel encodersSensor(leftChassisEncoder, rightChassisEncoder, leftGateEncoder, rightGateEncoder);
		ButtonsModel buttonSensor(stopButton);
		UltrasonicModel ultrasonicModel(gateUltrasonicSensor);
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
		Logic logic(controller, ultrasonicModel, gateDiode);

		try {
			logic.startThread();

			while (true) {
				if (buttonSensor.getStopButton()) {
					raise(SIGINT);
				}
			}
		} catch (...) {
		}

		teardown(-1);
	}


	static void teardown(int signal)
	{
		/*try {
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
		catch (...) {}*/

		Helpers::dump(Helpers::Debug, "Teardown");

		/*
		if(Motor::get_motors().size() != 0){
			Motor::lock = true;
		}
		*/

		for (auto motor : Motor::get_motors()) {
			motor->setPower(0);
			motor->lock = true;
		}

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