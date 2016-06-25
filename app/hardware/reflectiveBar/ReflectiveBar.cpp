//
// Created by Martin Mikšík
//

#include "ReflectiveBar.h"

vector<int> ReflectiveBar::getData()
{
	pipe << command << "\n";

	vector<int> values;
	for (auto &i: values) {
		pipe >> i;
	}

	pipe.flush();

	return values;
}