#ifndef INPUT_PROVIDER_H
#define INPUT_PROVIDER_H

#include "vector2.h"

class InputProvider {
public:
	virtual ~InputProvider() {}
	virtual Vector2 getMovementDirection() = 0;
};

#endif