#ifndef PLAYER_H
#define PLAYER_H

#include "game_object.h"
#include "gun.h"
#include "vector2.h"

/// @brief A játékos osztálya.
class Player : public GameObject {
public:
	explicit Player(const Vector2& position);
	void update() override;
	void onCollision(const GameObject* other) override;

private:
	Gun _gun;
};

#endif