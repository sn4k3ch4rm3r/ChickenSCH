#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "game_object.h"
#include "vector2.h"

namespace ProjectileConstants {
const int EGG_VELOCITY = 100;
const int POWERUP_VELOCITY = 60;
}  // namespace ProjectileConstants

/// @brief Lövedék típusú objektumok.
class Projectile : public GameObject {
public:
	/// @brief Lövedék konstruktor.
	/// @param position A lövedék kiindulási pozíciója.
	/// @param velocity A lövedék sebessége.
	/// @param tag Az ütközési címke.
	Projectile(const Vector2& position, const Vector2& velocity, CollisionTag tag);

	/// @brief Ütközés ellenőrzése.
	/// @param other A másik játékobjektum.
	/// @return Igaz, ha ütközik, egyébként hamis.
	bool checkCollision(const GameObject* other) const override;

	/// @brief Ellenőrzi, hogy lövedék-e az objektum.
	/// @return Igaz, ha lövedék, egyébként hamis.
	bool isProjectile() const override { return true; }
};

#endif