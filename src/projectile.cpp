#include "projectile.h"
#include "game.h"
#include "scene_manager.h"

Projectile::Projectile(const Vector2& position, const Vector2& velocity, CollisionTag tag)
    : GameObject(position) {
	_velocity = velocity;
	_tag = tag;
	switch (tag) {
		case PLAYER:
			_texture = SceneManager::getInstance().getPresentation()->loadTexture("assets/laser.png");
			break;
		case ENEMY:
			_texture = SceneManager::getInstance().getPresentation()->loadTexture("assets/egg.png");
			break;
		case POWERUP:
			_texture = SceneManager::getInstance().getPresentation()->loadTexture("assets/powerup.png");
			break;
		case NONE:
			break;
	}
}

bool Projectile::checkCollision(const GameObject* other) const {
	if (other->isProjectile()) {
		return false;
	}
	if ((other->getTag() == ENEMY && _tag == POWERUP)) {
		return false;
	}
	return GameObject::checkCollision(other);
}