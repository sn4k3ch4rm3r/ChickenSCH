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
private:
	bool _isRunning;
	double _lastTime;
	std::vector<Entity*> _entities;

public:
	static double deltaTime;
	static const int width = 320;
	static const int height = 180;
	static IPresentationFacade* presentation;

	Game();
	~Game();

	void gameLoop();
	void handleEvents();
	void render();
	void update();
};

#endif