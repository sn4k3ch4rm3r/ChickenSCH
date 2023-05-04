#include <iostream>
#include <queue>

#ifndef CPORTA
#include "sdl_presentation.h"
#else
//TODO: include JPORTA presentation facade
#endif

#include "game.h"
#include "player.h"
#include "texture.h"

Game Game::_instance;
Game& Game::getInstance() {
	return _instance;
}

Game::Game()
    : _isRunning(false) {

	// TODO: Either add a prepocessor or outsource to a factory
	_presentation = new SDLPresentationFacade("ChickenSCH", _width, _height);

	_entities.push_back(new Player(_width / 2, _height - 24));
	_isRunning = true;
	_deltaTime = 0;
}

Game::~Game() {
	delete _presentation;
}

void Game::gameLoop() {
	while (_isRunning) {
		_lastTime = SDL_GetPerformanceCounter();
		handleEvents();
		update();
		render();
		_deltaTime = (SDL_GetPerformanceCounter() - _lastTime) / SDL_GetPerformanceFrequency();
	}
}

void Game::handleEvents() {
	_presentation->handleEvents();
	_isRunning = _presentation->isRunning();
}

void Game::update() {
	for (size_t i = 0; i < _entities.size(); i++) {
		_entities[i]->update();
	}
}

void Game::render() {
	_presentation->clearScreen();
	for (auto& entity : _entities) {
		entity->render();
	}
	_presentation->renderScreen();
}

double Game::getDeltaTime() const {
	return _deltaTime;
}

double Game::getWidth() const {
	return _width;
}

double Game::getHeight() const {
	return _height;
}

IPresentationFacade* Game::getPresentation() const {
	return _presentation;
}