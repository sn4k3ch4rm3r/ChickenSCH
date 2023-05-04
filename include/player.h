#ifndef PLAYER_H
#define PLAYER_H

#include "entity.h"
#include "vector2.h"

class Player : public Entity {
public:
	Player();
	void update() override;
};

#endif