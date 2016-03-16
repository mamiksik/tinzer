#pragma once

#include <string>

using namespace std;

#ifndef KETCHUPHOUSE_FRUIT_H
#define KETCHUPHOUSE_FRUIT_H

class Fruit
{
public:
	Fruit(void);

	~Fruit(void);

	int getXPos();

	void setXPos(int x);

	int getYPos();

	void setYPos(int y);

private:

	int xPos, yPos;
	string type;

};

#endif //KETCHUPHOUSE_FRUIT_H
