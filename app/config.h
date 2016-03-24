#include <mutex>
#include <stack>

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



mutex mtx;
stack coordinatesStack;

struct Coordinates
{
	Coordinates(int angle, short y, short x)
			: angle(angle), y(y),
			  x(x)
	{ }

	short int y;
	short int x;

	//1 = full rotation
	//Why we wanted to store it as rad?
	int angle;
};


struct Instruction
{
	Instruction(bool action, double distance, int power) : action(action), distance(distance), power(power)
	{ }

	//1 = move forward 0 = turn
	bool action;
	double distance;
	int power;
};