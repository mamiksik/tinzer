//
// Created by Martin Mikšík
//

#ifndef KETCHUPHOUSE_CONFIG_H
#define KETCHUPHOUSE_CONFIG_H

#include <math.h>
#include "../framework/Log.h"

//Debuging
const int LOG_LEVEL = Log::All;

//Grid Position
const int DEFAULT_X_POSITION = 0;
const int DEFAULT_Y_POSITION = 0;
const double DEFAULT_ROTATION = M_PI;

//Grid definition
const int LINE_LEIGHT = 100; //mm

//Motor
//const int MOTOR_CONTROL_UPADTE_RATE = 50;

//Encoder sensors
const int ENCODER_SENSORS_UPDATE_RATE = 50;
const int ENCODER_RESOLUTION = 360; //Ticks peer rev...
const int LEFT_ENCODER_FIX = 1;
const int RIGHT_ENCODER_FIX = 1;

//Robot definition
const double WHEEL_DISTANCE = 180;
const double WHEEL_DIAMETER = 80;

#endif //KETCHUPHOUSE_CONFIG_H