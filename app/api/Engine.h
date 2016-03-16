//
// Created by Martin Mikšík on 12/03/16.
//

#ifndef KETCHUPHOUSE_ENGINE_H
#define KETCHUPHOUSE_ENGINE_H


class Engine {
public:
	int getEncoderRel(void);

	void setPosition(double, int);

private:
	int lastEncoder;
};


#endif //KETCHUPHOUSE_ENGINE_H
