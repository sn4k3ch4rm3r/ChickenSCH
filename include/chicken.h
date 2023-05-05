#ifndef CHICKEN_H
#define CHICKEN_H

#include "game_object.h"

class Chicken : public GameObject {
public:
	Chicken();

	void update();
};

#endif