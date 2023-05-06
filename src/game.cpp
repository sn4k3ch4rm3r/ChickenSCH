#include "game.h"
#include "game_object.h"
#include "player.h"
#include "presentation.h"
#include "scene_manager.h"
#include "texture.h"

Game::Game()
    : _isGameOver(false) {
	Size _size = SceneManager::getInstance().getSize();
	_entities.push_back(new Player(_size.getWidth() / 2, _size.getHeight() - 24));
}

Game::~Game() {
	for (auto& entity : _entities) {
		delete entity;
	}
}

void Game::update() {
	for (size_t i = 0; i < _entities.size(); i++) {
		_entities[i]->update();
	}
	_nextScene = this;
}

void Game::render() {
	IPresentation* _presentation = SceneManager::getInstance().getPresentation();
	_presentation->clearScreen();
	for (auto& entity : _entities) {
		entity->render();
	}
	_presentation->renderScreen();
}
