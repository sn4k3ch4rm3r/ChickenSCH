#include "chickens.h"
#include <cstdlib>
#include "game.h"
#include "game_object.h"
#include "projectile.h"
#include "scene_manager.h"

Chicken::Chicken(const Vector2& position, int difficulty)
    : GameObject(position) {
	_health = difficulty;
	_tag = ENEMY;
}

void Chicken::update() {
	if ((double)rand() / RAND_MAX < 0.001) {
		static_cast<Game*>(SceneManager::getInstance().getCurrentScene())->addEntity(new Projectile(_position, Vector2(0, 100), ENEMY));
	}
	GameObject::update();
}

void Chicken::onCollision(const GameObject* other) {
	GameObject::onCollision(other);
	if (_health <= 0 && other->getTag() != POWERUP && (double)rand() / RAND_MAX < 0.01) {
		static_cast<Game*>(SceneManager::getInstance().getCurrentScene())->addEntity(new Projectile(_position, Vector2(0, 60), POWERUP));
	}
}

OrderedChicken::OrderedChicken(const Vector2& position, int difficulty)
    : Chicken(position, difficulty), _direction(-1), _startingX(position.getX()) {
	_texture = SceneManager::getInstance().getPresentation()->loadTexture("assets/blue_chicken.png");
}

void OrderedChicken::update() {
	if (_position.getX() - _startingX > 80) {
		_direction = -1;
	} else if (_position.getX() - _startingX <= 0) {
		_direction = 1;
	}
	_velocity = Vector2(50 * _direction, 0);
	Chicken::update();
}

RandomChicken::RandomChicken(const Vector2& position, int difficlutly)
    : Chicken(position, difficlutly), _direction((double)rand() / RAND_MAX < 0.5 ? -1 : 1) {
	_texture = SceneManager::getInstance().getPresentation()->loadTexture("assets/pink_chicken.png");
	_velocity = Vector2(50 * _direction, 50);
}

void RandomChicken::update() {
	if (_position.getX() <= 0 || _position.getX() >= 320) {
		_velocity.setX(-_velocity.getX());
	}
	Chicken::update();
}