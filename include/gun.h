#ifndef GUN_H
#define GUN_H

#include "vector2.h"

class Gun {
public:
	Gun();
	void shoot(Vector2 position);
	void upgrade();
	void reset();

private:
	int _level;
};

#endif