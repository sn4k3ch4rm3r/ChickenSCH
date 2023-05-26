#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "game_object.h"
#include "vector2.h"

namespace ProjectileConstants {
const int EGG_VELOCITY = 100;
const int POWERUP_VELOCITY = 60;
}  // namespace ProjectileConstants

class Projectile : public GameObject {
public:
	Projectile(const Vector2& position, const Vector2& velocity, CollisionTag tag);

	bool checkCollision(const GameObject* other) const override;
	bool isProjectile() const override { return true; }
};

#endif