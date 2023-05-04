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

double Game::deltaTime = 0;

IPresentationFacade* Game::presentation = nullptr;
Game::Game()
    : _isRunning(false) {

	// TODO: Either add a prepocessor or outsource to a factory
	presentation = new SDLPresentationFacade("ChickenSCH", width, height);

	_entities.push_back(new Player());

	_isRunning = true;
}

Game::~Game() {
	delete presentation;
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
	presentation->handleEvents();
	_isRunning = presentation->isRunning();
}

void Game::update() {
	for (size_t i = 0; i < _entities.size(); i++) {
		_entities[i]->update();
	}
}

void Game::render() {
	presentation->clearScreen();
	for (auto& entity : _entities) {
		entity->render();
	}
	presentation->renderScreen();
}