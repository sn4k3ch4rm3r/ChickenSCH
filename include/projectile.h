#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "game_object.h"
#include "vector2.h"

class Projectile : public GameObject {
public:
	Projectile(const Vector2& position, const Vector2& velocity, CollisionTag tag);

	void update() override;
};

#endif