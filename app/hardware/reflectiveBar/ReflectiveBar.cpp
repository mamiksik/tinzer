//
// Created by Martin Mikšík
//

#include "ReflectiveBar.h"

vector<int> Hardware::ReflectiveBar::getData()
{
	pipe << comand;

	vector<int> values;
	for (auto &i: values) {
		pipe >> i;
	}

	pipe.flush();

	return values;
}