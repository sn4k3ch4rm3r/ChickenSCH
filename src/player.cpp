#include "player.h"
#include "game.h"
#include "projectile.h"
#include "scene_manager.h"

Player::Player(const Vector2& position)
    : GameObject(position, PLAYER, 3) {
	setTexture(SceneManager::getInstance().getPresentation()->loadTexture("assets/ship.png"));
}

void Player::update() {
	const SceneManager& context = SceneManager::getInstance();
	setVelocity(context.getPresentation()->getInputProvider()->getMovementDirection() * 200);

	if (((getPosition() - getTexture()->getSize() / 2).getX() < 0 && getVelocity().getX() < 0) ||
	    ((getPosition() + getTexture()->getSize() / 2).getX() > context.getSize().getWidth() && getVelocity().getX() > 0)) {
		setVelocity(Vector2(0, getVelocity().getY()));
	}

	if (context.getPresentation()->getInputProvider()->isShooting()) {
		_gun.shoot(getPosition());
	}
	GameObject::update();
}

void Player::onCollision(const GameObject* other) {
	if (other->getTag() == POWERUP) {
		_gun.upgrade();
		return;
	}
	if (other->getTag() == ENEMY) {
		_gun.reset();
	}
	GameObject::onCollision(other);
}