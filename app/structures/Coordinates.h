#ifndef KETCHUPHOUSE_COORDINATES_H
#define KETCHUPHOUSE_COORDINATES_H

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

#endif //KETCHUPHOUSE_COORDINATES_H