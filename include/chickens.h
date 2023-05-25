#ifndef CHICKENS_H
#define CHICKENS_H

#include "game_object.h"

class Chicken : public GameObject {
public:
	Chicken(const Vector2& position, int difficulty);
	virtual void update();
	void onCollision(const GameObject* other) override;
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
	RandomChicken(const Vector2& position, int difficulty);

	void update() override;

private:
	int _direction;
};

class DescendingChicken : public Chicken {
public:
	DescendingChicken(const Vector2& position, int difficulty);

	void update() override;

private:
	int _direction;
	int _startingX;
};

#endif