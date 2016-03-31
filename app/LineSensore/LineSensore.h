//
// Created by Martin Mikšík on 25/03/16.
//

#ifndef KETCHUPHOUSE_LINESENSORE_H
#define KETCHUPHOUSE_LINESENSORE_H


#include "../structures/SensorsArray.h"

class LineSensore
{
public:
	void update();

	SensorsArray getLinePosition();

private:
	int *getSensores(); //TODO: What is returning type?
};


#endif //KETCHUPHOUSE_LINESENSORE_H
