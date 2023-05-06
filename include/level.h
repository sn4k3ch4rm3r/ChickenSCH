#ifndef LEVEL_H
#define LEVEL_H

#include <vector>
#include "game_object.h"

class Level {
public:
	virtual std::vector<GameObject*> getEntities() const = 0;
};

#endif