#ifndef KETCHUPHOUSE_CONFIG_H
#define KETCHUPHOUSE_CONFIG_H

#include <math.h>
#include "../framework/Helpers/Helpers.h"

//Framework settings
int const LOG_LEVEL = Helpers::All;


//Game settings
int const GAME_TIME = 10000; // 3min = 180 000; // 2min 120000
int const DEFAULT_POWER = 40;
int const ENEMY_DETECTION_DISTANCE = 20;


//ReflectiveBar settings
int const SENSOR_DISTANCE = 30;

//Robot position settings
const int DEFAULT_X_POSITION = 0;
const int DEFAULT_Y_POSITION = 0;
const double DEFAULT_ROTATION = M_PI_2;

//Grid settings
const int LINE_LEIGHT = 200; //mm

//Encoder settings
const int ENCODER_RESOLUTION = 360; //Ticks peer rev...

//Gates settings
const int GATE_TICS = 285;
const int GATE_POWER = 50;

//Robot settings
//const double WHEEL_DISTANCE = 170;
//const double WHEEL_DIAMETER = 80;

const double WHEEL_DISTANCE = 230;
const double WHEEL_DIAMETER = 70;

#endif //KETCHUPHOUSE_CONFIG_H