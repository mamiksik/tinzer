//
// Created by Martin Mikšík on 13/03/16.
//

#ifndef KETCHUPHOUSE_POSITION_H
#define KETCHUPHOUSE_POSITION_H

class Position {
public:
	Position(int width, int height, int startX, int startY) : sizeX(width), sizeY(height), start(startX, startY, 0),
	                                                          current(startX, startY, 0) { }

	Coordinates getPosition(void);

	Coordinates getStartPosition(void);

	void moveToPosition(int width, int height);

private:
	unsigned short int sizeX;
	unsigned short int sizeY;

	Coordinates start;
	Coordinates current;

	//?
	//Control control;
};

struct Coordinates {
	Coordinates(double angle, unsigned short height, unsigned short width) : angle(angle), height(height),
	                                                                         width(width) { }

	unsigned short int width;
	unsigned short int height;

	double angle;
};


#endif //KETCHUPHOUSE_POSITION_H
