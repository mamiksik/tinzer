//
// Created by Martin Mikšík on 12/03/16.
//

#include "Engine.h"

int Engine::getEncoderRel(void) {
	int encoder = 23; //TODO
	int result = lastEncoder - encoder;
	lastEncoder = encoder;
	return result;
}
