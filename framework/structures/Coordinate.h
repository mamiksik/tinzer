#ifndef KETCHUPHOUSE_COORDINATES_H
#define KETCHUPHOUSE_COORDINATES_H

namespace Structure {
	struct Coordinate
	{
		Coordinate(int x, int y, double rotation)
				: rotation(rotation), x(x), y(y)
		{}

		double rotation;
		int x;
		int y;

		bool operator==(const Coordinate& o) const {
			bool equal = true;
			if(x != o.x){
				equal = false;
			} else if (y != o.y){
				equal = false;
			} else if (rotation != o.rotation){
				equal = false;
			}

			return equal;
		}
	};
}

#endif //KETCHUPHOUSE_COORDINATES_H