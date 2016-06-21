//
// Created by Martin Mikšík
//

#include "ReflectiveBar.h"

vector<int> ReflectiveBar::getData()
{
	vector<int> values;

	//TODO: Insert command
	for (auto &i: values) {
		pipe >> i;
	}

	pipe.flush();

	return values;
}