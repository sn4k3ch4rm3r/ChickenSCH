#ifndef CHICKEN_H
#define CHICKEN_H

#include "game_object.h"

class Chicken : public GameObject {
public:
	Chicken();

	virtual void update();
};

class OrderChicken : public Chicken {
public:
	OrderChicken();

	void update();
};

class RandomChicken : public Chicken {
public:
	RandomChicken();

	void update();
};

class DescendingChicken : public Chicken {
public:
	DescendingChicken();

	void update();
};

#endif