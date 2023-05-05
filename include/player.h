#ifndef PLAYER_H
#define PLAYER_H

#include "game_object.h"
#include "vector2.h"

class Player : public GameObject {
public:
	Player(int x = 0, int y = 0);
	void update() override;
};

#endif