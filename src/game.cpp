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
#include "memtrace.h"

Game::Game()
    : _isGameOver(false), _score(0), _currentLevel(0), _activeEnemies(0) {
	Size _size = SceneManager::getInstance().getSize();
	_entities.push_back(
	    new Player(
	        Vector2(_size.getWidth() / 2, _size.getHeight() - 24)
	    )
	);
	_levels.push_back(new OrderedLevel());
	_levels.push_back(new OrderedLevel());
	_levels.push_back(new RandomLevel());
	_levels.push_back(new DescendingLevel());

	loadNextLevel();
}

Game::~Game() {
	for (const auto& entity : _entities) {
		delete entity;
	}
	for (const auto& level : _levels) {
		delete level;
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

	//TODO: Move memory management out of the predicate
	_entities.remove_if([this](GameObject* entity) {
		bool shouldRemove = !entity->isAlive() || entity->getPosition().getY() < -10 || entity->getPosition().getY() > SceneManager::getInstance().getSize().getHeight() + 10;

		if (shouldRemove) {
			if (entity->getTag() == ENEMY && !entity->isProjectile()) {
				_activeEnemies--;
				if (!entity->isAlive()) {
					_score += 100;
				}
			}
			delete entity;
		}
		return shouldRemove;
	});

	for (auto it = _entities.begin(); it != _entities.end(); it++) {
		(*it)->update();
	}

	if (_activeEnemies == 0) {
		loadNextLevel();
	}
}

void Game::render() {
	IPresentation* _presentation = SceneManager::getInstance().getPresentation();
	_presentation->clearScreen();
	for (auto& entity : _entities) {
		entity->render();
	}
	_presentation->renderText(("Score: " + std::to_string(_score)).c_str(), Vector2(10, 10));
	_presentation->renderText(("Lives: " + std::to_string(_entities.front()->getHealth())).c_str(), Vector2(10, 25));
	_presentation->renderScreen();
}

void Game::addEntity(GameObject* entity) {
	_entities.push_back(entity);
}

void Game::loadNextLevel() {
	_activeEnemies = (*_levels[_currentLevel % _levels.size()])(this);
	_levels[_currentLevel % _levels.size()]->increaseDifficulty();
	_currentLevel++;
}