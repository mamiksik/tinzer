#ifndef KETCHUPHOUSE_CONFIG_H
#define KETCHUPHOUSE_CONFIG_H

#include <cmath>
#include "../framework/Helpers/Helpers.h"
#include "../framework/libs/iniReader/INIReader.h"

//Framework settings
const int LOG_LEVEL = Helpers::All;

extern INIReader reader;

//Game settings
const int GAME_TIME = reader.GetInteger("game", "time", 120000);//100000; // 3min = 180 000; // 2min 120000
const int LINE_LENGHT = reader.GetInteger("game", "line_leight", 200); //mm

//Robot settings
const int DEFAULT_POWER = reader.GetInteger("robot", "power", 40);

const int DEFAULT_X_POSITION = reader.GetInteger("robot", "x_position", 0);
const int DEFAULT_Y_POSITION = reader.GetInteger("robot", "y_position", 0);
const double DEFAULT_ROTATION = reader.GetReal("robot", "rotation", M_PI_2);

const int ENEMY_DETECTION_DISTANCE = reader.GetInteger("robot", "enemy_distance", 0);

//ReflectiveBar settings
const int SENSOR_DISTANCE = reader.GetInteger("reflective_bar", "sensor_distance", 30);


//Gates settings


const int GATE_TICS = reader.GetInteger("gate", "tics", 285);
const int GATE_POWER = reader.GetInteger("gate", "power", 50);

//Robot settings
//const double WHEEL_DISTANCE = 170;
//const double WHEEL_DIAMETER = 80;

const double WHEEL_DISTANCE = reader.GetInteger("control", "wheel_distance", 230);
const double WHEEL_DIAMETER = reader.GetInteger("control", "wheel_diameter", 70);
const int ENCODER_RESOLUTION = reader.GetInteger("control", "encoder_resolution", 360); //mm //Ticks peer rev...

#endif //KETCHUPHOUSE_CONFIG_H