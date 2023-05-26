#ifndef GAME_H
#define GAME_H

#include <list>
#include <vector>
#include "game_object.h"
#include "levels.h"
#include "scene.h"

class Game : public Scene {
public:
	Game();
	~Game();

	void render() override;
	void update() override;

	void addEntity(GameObject* entity);

private:
	void loadNextLevel();
	bool _isGameOver;
	std::vector<Level*> _levels;
	std::list<GameObject*> _entities;
	int _score;
	int _currentLevel;
	int _activeEnemies;
};

#endif