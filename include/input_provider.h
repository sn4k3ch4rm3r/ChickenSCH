#ifndef INPUT_PROVIDER_H
#define INPUT_PROVIDER_H

#include "vector2.h"

class InputProvider {
public:
	virtual ~InputProvider() {}
	virtual Vector2 getMovementDirection() const = 0;
	virtual bool isShooting() = 0;
	virtual void setCanShoot(bool canShoot) = 0;
};

#endif