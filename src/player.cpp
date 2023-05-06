#include "player.h"
#include "game.h"
#include "projectile.h"
#include "scene_manager.h"

Player::Player(int x, int y)
    : GameObject() {
	_texture = SceneManager::getInstance().getPresentation()->loadTexture("assets/ship.png");
	_position = Vector2(x, y);
}

void Player::update() {
	SceneManager& context = SceneManager::getInstance();
	_velocity = context.getPresentation()->getInputProvider()->getMovementDirection() * 200;

	if ((_position - _texture->getSize() / 2).getX() < 0 && _velocity.getX() < 0) {
		_velocity.setX(0);
	}
	if ((_position + _texture->getSize() / 2).getX() > context.getSize().getWidth() && _velocity.getX() > 0) {
		_velocity.setX(0);
	}

	if (context.getPresentation()->getInputProvider()->isShooting()) {
		_gun.shoot(_position);
	}
	GameObject::update();
}