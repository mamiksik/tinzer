//
// Created by Martin Mikšík
//

#ifndef KETCHUPHOUSE_LINESENSOR_H
#define KETCHUPHOUSE_LINESENSOR_H

#include <array>

using namespace std;


namespace Model {
	class LineModel
	{
	public:
		//0. x, 1. y 2. rotation
		array<int, 3> getCorectionData();
	};
}


#endif //KETCHUPHOUSE_LINESENSOR_H
