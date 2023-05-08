#ifndef PLAYER_H
#define PLAYER_H

#include "game_object.h"
#include "gun.h"
#include "vector2.h"

class Player : public GameObject {
public:
	Player(const Vector2& position);
	void update() override;

private:
	Gun _gun;
};

#endif