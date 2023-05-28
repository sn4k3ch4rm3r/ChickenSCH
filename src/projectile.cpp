#include "projectile.h"
#include "game.h"
#include "scene_manager.h"

Projectile::Projectile(const Vector2& position, const Vector2& velocity, CollisionTag tag)
    : GameObject(position) {
	setVelocity(velocity);
	setTag(tag);
	switch (tag) {
		case PLAYER:
			setTexture(SceneManager::getInstance().getPresentation()->loadTexture("laser.png"));
			break;
		case ENEMY:
			setTexture(SceneManager::getInstance().getPresentation()->loadTexture("egg.png"));
			break;
		case POWERUP:
			setTexture(SceneManager::getInstance().getPresentation()->loadTexture("powerup.png"));
			break;
		case NONE:
			break;
	}
}

bool Projectile::checkCollision(const GameObject* other) const {
	if (other->isProjectile()) {
		return false;
	}
	if ((other->getTag() == ENEMY && getTag() == POWERUP)) {
		return false;
	}
	return GameObject::checkCollision(other);
}