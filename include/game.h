#ifndef GAME_H
#define GAME_H

#include <vector>
#include "game_object.h"
#include "presentation.h"

class Game {
public:
	static Game& getInstance();
	Game(const Game&) = delete;
	Game& operator=(const Game&) = delete;
	~Game();

	void gameLoop();
	void handleEvents();
	void render();
	void update();

	double getDeltaTime() const;
	double getWidth() const;
	double getHeight() const;
	IPresentationFacade* getPresentation() const;

private:
	Game();
	static Game _instance;
	double _deltaTime;
	const int _width = 320;
	const int _height = 180;
	IPresentationFacade* _presentation;
	bool _isRunning;
	double _lastTime;
	std::vector<GameObject*> _entities;
};

#endif