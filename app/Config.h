#ifndef KETCHUPHOUSE_CONFIG_H
#define KETCHUPHOUSE_CONFIG_H

#include <math.h>
#include "../framework/Helpers/Helpers.h"

//Framework settings
int const LOG_LEVEL = Helpers::All;

//Robot position settings
const int DEFAULT_X_POSITION = 0;
const int DEFAULT_Y_POSITION = 0;
const double DEFAULT_ROTATION = 0;

//Grid settings
const int LINE_LEIGHT = 200; //mm

//Encoder settings
const int ENCODER_SENSORS_UPDATE_RATE = 60; //ms
const int ENCODER_RESOLUTION = 360; //Ticks peer rev...

//Gate settings
const int GATE_COLOR_SENSORS_UPDATE_RATE = 170;

//Robot settings
//const double WHEEL_DISTANCE = 170;
//const double WHEEL_DIAMETER = 80;

const double WHEEL_DISTANCE = 230;
const double WHEEL_DIAMETER = 70;

#endif //KETCHUPHOUSE_CONFIG_H