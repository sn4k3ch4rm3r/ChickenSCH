#include <SDL.h>
#include <iostream>

#include "game.h"
#include "player.h"

double Game::deltaTime = 0;
SDL_Renderer* Game::renderer = nullptr;

Game::Game(const char* title, const int width, const int height)
    : _window(NULL), _width(width), _height(height), _isRunning(false) {

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		std::cerr << "Error while initializing SDL: " << SDL_GetError() << std::endl;
	}

	_window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width * PIXEL_SIZE, height * PIXEL_SIZE, SDL_WINDOW_SHOWN);
	if (_window == NULL) {
		std::cerr << "Error while creating window: " << SDL_GetError() << std::endl;
	}

	renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE);
	if (renderer == NULL) {
		std::cerr << "Error while creating renderer: " << SDL_GetError() << std::endl;
	}

	SDL_RenderSetLogicalSize(renderer, width, height);

	_player = Player();
	_player.setPosition(Vector2(_width / 2, _height - 32));

	_isRunning = true;
}

Game::~Game() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(_window);
}

void Game::gameLoop() {
	while (_isRunning) {
		_lastTime = SDL_GetPerformanceCounter();
		handleEvents();
		update();
		render();
		deltaTime = (SDL_GetPerformanceCounter() - _lastTime) / SDL_GetPerformanceFrequency();
	}
}

void Game::handleEvents() {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
			case SDL_QUIT:
				_isRunning = false;
				break;
			case SDL_KEYDOWN:
			case SDL_KEYUP: {
				bool isPressed = event.key.state == SDL_PRESSED;
				switch (event.key.keysym.sym) {
					case SDLK_a:
						_player.setVelocity(Vector2(-200, 0) * isPressed);
						break;
					case SDLK_d:
						_player.setVelocity(Vector2(200, 0) * isPressed);
						break;
					default:
						break;
				}
				break;
			}
			default:
				break;
		}
	}
}

void Game::update() {
	_player.update();
}

void Game::render() {
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

	_player.render();

	SDL_RenderPresent(renderer);
}
