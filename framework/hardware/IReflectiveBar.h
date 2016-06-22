//
// Created by Martin Mikšík
//

#ifndef KETCHUPHOUSE_IREFLECTIVEBAR_H
#define KETCHUPHOUSE_IREFLECTIVEBAR_H

#include <vector>

using namespace std;

namespace Interfaces {
	namespace Hardware {
		class IReflectiveBar
		{
		public:
			IReflectiveBar()
			{}

			virtual ~IReflectiveBar()
			{}

			virtual vector<int> getData() = 0;
		};
	}
}

#endif //KETCHUPHOUSE_IREFLECTIVEBAR_H
