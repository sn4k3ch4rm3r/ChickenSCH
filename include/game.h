#ifndef GAME_H
#define GAME_H

#include <SDL.h>
#include "player.h"

class Game {
private:
	static const int PIXEL_SIZE = 3;
	SDL_Window* _window;

	int _width;
	int _height;
	bool _isRunning;

	Player _player;
	double _lastTime;

public:
	static SDL_Renderer* renderer;
	static double deltaTime;

	Game(const char* title, const int width, const int height);
	~Game();

	void gameLoop();
	void handleEvents();
	void render();
	void update();
};

#endif