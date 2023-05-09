#include "game.h"
#include <algorithm>
#include <vector>
#include "chickens.h"
#include "game_object.h"
#include "levels.h"
#include "player.h"
#include "presentation.h"
#include "scene_manager.h"
#include "texture.h"

Game::Game()
    : _isGameOver(false) {
	Size _size = SceneManager::getInstance().getSize();
	_entities.push_back(new Player(Vector2(_size.getWidth() / 2, _size.getHeight() - 24)));
	OrderedLevel level = OrderedLevel();
	level(this);
}

Game::~Game() {
	for (auto& entity : _entities) {
		delete entity;
	}
}

void Game::update() {
	for (auto it = _entities.begin(); it != _entities.end(); it++) {
		for (auto it2 = _entities.begin(); it2 != _entities.end(); it2++) {
			if (it != it2 && (*it)->checkCollision(*it2)) {
				(*it)->onCollision(*it2);
			}
		}
	}

	_entities.remove_if([](GameObject* entity) {
		bool shouldRemove = !entity->isAlive() || entity->getPosition().getY() < -10 || entity->getPosition().getY() > SceneManager::getInstance().getSize().getHeight() + 10;
		if (shouldRemove) {
			delete entity;
		}
		return shouldRemove;
	});

	for (auto it = _entities.begin(); it != _entities.end(); it++) {
		(*it)->update();
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

void Game::addEntity(GameObject* entity) {
	_entities.push_back(entity);
}

void Game::removeEntity(GameObject* entity) {
	// _entities.erase(std::remove(_entities.begin(), _entities.end(), entity), _entities.end());
	_entities.remove(entity);
	delete entity;
}