#include "projectile.h"
#include "game.h"
#include "scene_manager.h"

Projectile::Projectile(const Vector2& position, const Vector2& velocity, CollisionTag type)
    : GameObject(position) {
	_velocity = velocity;
	switch (type) {
		case PLAYER:
			_texture = SceneManager::getInstance().getPresentation()->loadTexture("assets/laser.png");
			break;
		case ENEMY:
			_texture = SceneManager::getInstance().getPresentation()->loadTexture("assets/egg.png");
			break;
		case POWERUP:
			_texture = SceneManager::getInstance().getPresentation()->loadTexture("assets/powerup.png");
			break;
	}
}

void Projectile::update() {
	if (_position.getY() < -10 || _position.getY() > SceneManager::getInstance().getSize().getHeight() + 10) {
		static_cast<Game*>(SceneManager::getInstance().getCurrentScene())->removeEntity(this);
		delete this;
		return;
	}
	GameObject::update();
}