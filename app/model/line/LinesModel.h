//
// Created by Martin Mikšík
//

#ifndef KETCHUPHOUSE_LINESENSOR_H
#define KETCHUPHOUSE_LINESENSOR_H

#include <array>

using namespace std;


namespace Model {
	class LinesModel
	{
	public:
		array<int, 3> getCorectionData();
	};
}


#endif //KETCHUPHOUSE_LINESENSOR_H
