#ifndef KETCHUPHOUSE_COORDINATES_H
#define KETCHUPHOUSE_COORDINATES_H

namespace structure {

	struct Coordinate
	{
		typedef short int position;
		typedef double radian;

		Coordinate(int angle, position x, position y)
				: angle(angle), y(y),
				  x(x)
		{ }

		position x;
		position y;

		//1 = full rotation
		//Why we wanted to store it as rad?
		radian angle;
	};
}

#endif //KETCHUPHOUSE_COORDINATES_H