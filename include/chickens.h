#ifndef CHICKENS_H
#define CHICKENS_H

#include "game_object.h"

namespace ChickenConstants {
const double EGG_PROBABILITY = 0.0005;
const double POWERUP_PROBABILITY = 0.01;
const int BASE_VELOCITY_X = 50;
const int BASE_VELOCITY_Y = 10;
const double SPEED_INCREASE = 2;
const double EGG_INCREASE = 0.0001;
const double SPEED_VARIATION = 0.4;
}  // namespace ChickenConstants

enum Direction {
	LEFT = -1,
	RIGHT = 1
};

class Chicken : public GameObject {
public:
	Chicken(const Vector2& position, int health);
	virtual void update() override;
	void onCollision(const GameObject* other) override;
	double getEggProbability() const { return _eggProbability; }
	Direction getDirection() const { return _direction; }
	void setDirection(Direction direction) { _direction = direction; }

private:
	double _eggProbability;
	Direction _direction;
};

class OrderedChicken : public Chicken {
public:
	OrderedChicken(const Vector2& position, int health);
	void update() override;

private:
	int _startingX;
};

class RandomChicken : public Chicken {
public:
	RandomChicken(const Vector2& position, int health);

	void update() override;
};

class DescendingChicken : public Chicken {
public:
	DescendingChicken(const Vector2& position, int health);

	void update() override;

private:
	int _startingX;
};

#endif