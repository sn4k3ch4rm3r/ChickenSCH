#ifndef ENTITY_H
#define ENTITY_H

#include "vector2.h"

class Entity {
protected:
	Vector2 position;
	Vector2 velocity;

public:
	Entity()
	    : position(0, 0), velocity(0, 0){};
	virtual void render() = 0;
	virtual void update();

	Vector2 getPosition() const;
	void setPosition(const Vector2& position);
	Vector2 getVelocity() const;
	void setVelocity(const Vector2& velocity);
};

#endif