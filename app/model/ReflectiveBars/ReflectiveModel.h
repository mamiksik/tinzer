//
// Created by Martin Mikšík
//

#ifndef KETCHUPHOUSE_REFLECTIVEMODEL_H
#define KETCHUPHOUSE_REFLECTIVEMODEL_H


#include "../../hardware/reflectiveBar/ReflectiveBar.h"

class ReflectiveModel
{
public:
	int getPositionFromCenterLeft();
	int getPositionFromCenterRight();
	int getPositionFromCenterBottom();

	int process(vector<int> data);

private:
	ReflectiveBar &leftReflectiveBar;
	ReflectiveBar &rightReflectiveBar;
	ReflectiveBar &bottomReflectiveBar;
};


#endif //KETCHUPHOUSE_REFLECTIVEMODEL_H
