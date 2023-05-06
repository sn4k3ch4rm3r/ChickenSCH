#include "gun.h"
#include "game.h"
#include "projectile.h"
#include "scene_manager.h"

Gun::Gun()
    : _level(7) {}

void Gun::upgrade() {
	if (_level < 5) {
		_level++;
	}
}

const int SPREAD = 7;
void Gun::shoot(Vector2 position) {
	Vector2 velocity(0, -250);
	velocity = velocity.rotate(-SPREAD * (_level - 1) / 2);
	for (int i = 0; i < _level; i++) {
		static_cast<Game*>(SceneManager::getInstance().getCurrentScene())->addEntity(new Projectile(position, velocity, LASER));
		velocity = velocity.rotate(SPREAD);
	}
}
