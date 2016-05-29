#ifndef KETCHUPHOUSE_COORDINATES_H
#define KETCHUPHOUSE_COORDINATES_H

namespace structure {
	struct Coordinate
	{
		typedef int position;
		typedef double radian;

		Coordinate(radian rotation, position x, position y)
				: rotation(rotation), x(x), y(y)
		{}

		radian rotation;
		position x;
		position y;
	};
}

#endif //KETCHUPHOUSE_COORDINATES_H