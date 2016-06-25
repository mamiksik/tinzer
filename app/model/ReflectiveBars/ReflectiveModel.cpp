//
// Created by Martin Mikšík
//

#include "ReflectiveModel.h"
#include "../../Config.h"


int ReflectiveModel::getPositionFromCenterLeft()
{
	vector<int> data = leftReflectiveBar.getData();
	int index = process(data);

	return index * SENSOR_DISTANCE;
}

int ReflectiveModel::getPositionFromCenterRight()
{
	vector<int> data = rightReflectiveBar.getData();
	int index = process(data);

	return index * SENSOR_DISTANCE;
}

int ReflectiveModel::getPositionFromCenterBottom()
{
	vector<int> data = bottomReflectiveBar.getData();
	int index = process(data);

	return index * SENSOR_DISTANCE;
}


int ReflectiveModel::process(vector<int> data)
{
	//0 = White... Max = black
	int higherVal = 0;

	int i = 0;
	int index = 0;

	for(auto sensorVal: data){
		if(higherVal < sensorVal){
			higherVal = sensorVal;
			index = i;
		}
		i++;
	}

	//?????????
	if(index > 6){
		index = -index;
	}

	return index;
}