//
// Created by Martin Mikšík
//

#ifndef KETCHUPHOUSE_LINESENSOR_H
#define KETCHUPHOUSE_LINESENSOR_H

#include <string>
#include <array>
#include <fstream>
#include <vector>

#include "../../../framework/hardware/IReflectiveBar.h"

using namespace std;
using namespace Interfaces::Hardware;

namespace Hardware {
	class ReflectiveBar : public IReflectiveBar
	{
	public:
		ReflectiveBar(const string &pipeLocation, const string &comand) : comand(comand)
		{
			pipe = fstream(pipeLocation);
			if (!pipe.is_open()) {
				throw runtime_error("Cannot open pipe");
			}
		}

		vector<int> getData();

	private:
		fstream pipe;
		const string comand;
	};
}


#endif //KETCHUPHOUSE_LINESENSOR_H