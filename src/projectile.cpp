#include "projectile.h"
#include "game.h"
#include "scene_manager.h"

Projectile::Projectile(const Vector2& position, const Vector2& velocity, ProjectileType type)
    : GameObject() {
	_position = position;
	_velocity = velocity;
	_texture = SceneManager::getInstance().getPresentation()->loadTexture("assets/laser.png");
}

Projectile::~Projectile() {
	delete _texture;
}

void Projectile::update() {
	if (_position.getY() < 0) {
		static_cast<Game*>(SceneManager::getInstance().getCurrentScene())->removeEntity(this);
		delete this;
		return;
	}
	GameObject::update();
}