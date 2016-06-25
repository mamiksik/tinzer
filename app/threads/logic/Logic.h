//
// Created by Martin Mikšík
//

#ifndef KETCHUPHOUSE_BRAINTHREAD_H
#define KETCHUPHOUSE_BRAINTHREAD_H

#include "../../../framework/threading/Threading.h"
#include "../controller/Controller.h"
#include "../../model/ultrasonic/UltrasonicModel.h"
#include "../../hardware/diode/Diode.h"
#include "../../hardware/button/Button.h"
#include "../../model/button/ButtonsModel.h"

using namespace std;

class Logic : public Threading
{
public:

	Logic(Controller &controller, UltrasonicModel &ultrasonicModel, ButtonsModel &buttonsModel, Diode &gateDiode)
			: controller(controller), ultrasonicModel(ultrasonicModel), buttonsModel(buttonsModel), gateDiode(gateDiode)
	{}


	virtual ~Logic()
	{
		stopThread();
	}


private:
	Controller &controller;
	UltrasonicModel &ultrasonicModel;
	ButtonsModel &buttonsModel;
	Diode &gateDiode;

	virtual void threadTask();

	void goHome();
};


#endif //KETCHUPHOUSE_BRAINTHREAD_H
