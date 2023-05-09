#ifndef GAME_H
#define GAME_H

#include <list>
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
	void removeEntity(GameObject* entity);

private:
	bool _isGameOver;
	Level* _levels[4];
	std::list<GameObject*> _entities;
	int _score;
	int _curretnLevel;
};

#endif