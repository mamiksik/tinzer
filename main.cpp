#include <iostream>
#include "app/api/Engine.h"
#include "app/control/Control.h"
#include "app/grid/Position.h"

using namespace std;

bool update = true;

Engine leftEngine = Engine();
Engine rightEngine = Engine();

int main(int argc, char *argv[])
{
	//START OF CONFIG
	//Control
	int wheelDiameter = 12;
	int wheelsDistance = 30;

	//Position
	int width = 7;
	int height = 7;

	int startX = 4;
	int startY = 4;
	int startAngle = 0;
	//END OF CONFIG

	Control control = Control(wheelDiameter, wheelsDistance, leftEngine, rightEngine);
	Position position = Position(width, height, startX, startY, startAngle, control);

	do {
		//position.moveToPosition(4, 5);
	} while (update);
}