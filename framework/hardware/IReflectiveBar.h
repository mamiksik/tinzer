//
// Created by Martin Mikšík
//

#ifndef KETCHUPHOUSE_IREFLECTIVESENSORBAR_H
#define KETCHUPHOUSE_IREFLECTIVESENSORBAR_H

#include <vector>

using namespace std;

class IReflectiveBar
{
	virtual vector<int> getData() = 0;
};

#endif //KETCHUPHOUSE_IREFLECTIVESENSORBAR_H
