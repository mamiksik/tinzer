//
// Created by Martin Mikšík on 22/03/16.
//

#ifndef KETCHUPHOUSE_CONFIG_H
#define KETCHUPHOUSE_CONFIG_H

class Config
{
	//Control
	const static int wheelDiameter = 12;
	const static int wheelsDistance = 30;

	//Position
	const static int width = 7;
	const static int height = 7;

	const static int startX = 4;
	const static int startY = 4;
	const static int startAngle = 0;

	//Chrono
	const static int gameTime = 10; //v sec
	const static int maxTimeLoop = 30; //v ms

public:
	static const int getGameTime()
	{
		return gameTime;
	}


	static const int getMaxTimeLoop()
	{
		return maxTimeLoop;
	}
};

#endif //KETCHUPHOUSE_CONFIG_H
