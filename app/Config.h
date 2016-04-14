//
// Created by Martin Mikšík
//

#ifndef KETCHUPHOUSE_CONFIG_H
#define KETCHUPHOUSE_CONFIG_H

#include <mutex>
#include <stack>

#include "structures/Coordinates.h"
#include "structures/Instruction.h"

//Control
//TODO: static?
const static int wheelDiameter = 12;
const static int wheelsDistance = 30;

//Position
const static int width = 7;
const static int height = 7;

const static Coordinates startCoordinates(4, 4, 0);

//Chrono
const static int gameTime = 10; //v sec
const static int maxTimeLoop = 30; //v ms

extern std::mutex mtx;
extern std::stack<Instruction> instructionsStack;

#endif //KETCHUPHOUSE_CONFIG_H
