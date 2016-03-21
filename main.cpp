#include <iostream>
#include "app/api/Engine.h"
#include "app/control/Control.h"
#include "app/grid/Position.h"
#include <chrono>

using namespace std;

bool update = true;

Engine leftEngine = Engine();
Engine rightEngine = Engine();

int main(int argc, char *argv[])
{
	//START OF CONFIG
	//Control
	const int wheelDiameter = 12;
	const int wheelsDistance = 30;

	//Position
	const int width = 7;
	const int height = 7;

	const int startX = 4;
	const int startY = 4;
	const int startAngle = 0;
	
	//chrono
	const int gameTime = 10; // nastavit cas v sekundach 
	
	//END OF CONFIG

	Control control = Control(wheelDiameter, wheelsDistance, leftEngine, rightEngine);
	Position position = Position(width, height, startX, startY, startAngle, control);

	chrono::system_clock::time_point clock_now = chrono::system_clock::now();
	time_t stopTime = chrono::system_clock::to_time_t(clock_now);

	stopTime = stopTime + gameTime;

	do {
		//position.moveToPosition(4, 5);
		chrono::system_clock::time_point clock_now = chrono::system_clock::now();
		if (chrono::system_clock::to_time_t(clock_now) >= stopTime) {
			break;
		}
	} while (update);
}