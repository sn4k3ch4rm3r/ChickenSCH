#ifndef PLAYER_H
#define PLAYER_H

#include "entity.h"
#include "vector2.h"

class Player : public Entity {
public:
	Player(int x = 0, int y = 0);
	void update() override;
};

#endif