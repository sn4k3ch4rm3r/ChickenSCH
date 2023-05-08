#ifndef CHICKENS_H
#define CHICKENS_H

#include "game_object.h"

class Chicken : public GameObject {
public:
	Chicken(const Vector2& position, int difficulty);
	virtual void update();
};

class OrderedChicken : public Chicken {
public:
	OrderedChicken(const Vector2& position, int difficulty);
	void update() override;

private:
	int _direction;
	int _startingX;
};

class RandomChicken : public Chicken {
public:
	RandomChicken();

	void update() override;
};

class DescendingChicken : public Chicken {
public:
	DescendingChicken();

	void update() override;
};

#endif