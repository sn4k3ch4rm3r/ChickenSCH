#ifndef PLAYER_H
#define PLAYER_H

#include "entity.h"

class Player : public Entity {
public:
	Player()
	    : Entity(){};
	void update() override;
	void render() override;
};
#endif