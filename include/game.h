#ifndef GAME_H
#define GAME_H

#include <vector>
#include "entity.h"

#ifndef CPORTA
#include "sdl_presentation.h"
#else
//TODO: include JPORTA presentation facade
#endif

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
	std::vector<Entity*> _entities;
};

#endif