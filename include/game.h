#ifndef GAME_H
#define GAME_H

#include <vector>
#include "game_object.h"
#include "level_manager.h"
#include "scene.h"

class Game : public Scene {
public:
	Game();
	~Game();

	void render() override;
	void update() override;

	LevelManager& getLevelManager();

private:
	LevelManager _levelManager;
	bool _isGameOver;
	std::vector<GameObject*> _entities;
};

#endif