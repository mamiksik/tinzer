#ifndef KETCHUPHOUSE_COORDINATES_H
#define KETCHUPHOUSE_COORDINATES_H

namespace Structure {
	struct Coordinate
	{
		typedef int position;
		typedef double radian;


		//WARNING: Fixed switched axes
		Coordinate(position x, position y, radian rotation)
				: rotation(rotation), x(y), y(x)
		{}

		radian rotation;
		position x;
		position y;
	};
}

#endif //KETCHUPHOUSE_COORDINATES_H