#include "chickens.h"
#include <cstdlib>
#include "game.h"
#include "game_object.h"
#include "projectile.h"
#include "scene_manager.h"

Chicken::Chicken(const Vector2& position, int difficulty)
    : GameObject(position) {
	_health = difficulty;
}

void Chicken::update() {
	if ((double)rand() / RAND_MAX < 0.001) {
		static_cast<Game*>(SceneManager::getInstance().getCurrentScene())->addEntity(new Projectile(_position, Vector2(0, 100), ENEMY));
	}
	GameObject::update();
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