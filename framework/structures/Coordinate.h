#ifndef KETCHUPHOUSE_COORDINATES_H
#define KETCHUPHOUSE_COORDINATES_H

namespace structure {

	struct Coordinate
	{
		typedef int position;
		typedef double radian;

		Coordinate(radian angle, position x, position y)
				: rotation(angle), x(x), y(y)
		{ }

		radian rotation;
		position x;
		position y;
	};
}

#endif //KETCHUPHOUSE_COORDINATES_H