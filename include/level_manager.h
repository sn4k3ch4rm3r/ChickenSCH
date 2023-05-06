#ifndef LEVEL_MANAGER_H
#define LEVEL_MANAGER_H

#include <vector>
#include "game_object.h"
#include "level.h"

class LevelManager {
public:
	LevelManager();
	~LevelManager();

	Level* getCurrentLevel() const;

private:
	int _currentLevel;
	std::vector<Level*> _levels;
};

#endif