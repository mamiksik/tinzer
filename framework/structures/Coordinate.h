#ifndef KETCHUPHOUSE_COORDINATES_H
#define KETCHUPHOUSE_COORDINATES_H

namespace structure {

	struct Coordinate
	{
		typedef int position;
		typedef double radian;

		Coordinate(int angle, position x, position y)
				: angle(angle), y(y),
				  x(x)
		{ }

		position x;
		position y;
		radian angle;
	};
}

#endif //KETCHUPHOUSE_COORDINATES_H