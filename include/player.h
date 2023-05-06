#ifndef PLAYER_H
#define PLAYER_H

#include "game_object.h"
#include "gun.h"
#include "vector2.h"

class Player : public GameObject {
public:
	Player(int x = 0, int y = 0);
	void update() override;

private:
	Gun _gun;
};

#endif