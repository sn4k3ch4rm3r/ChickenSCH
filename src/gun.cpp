#include "gun.h"
#include "game.h"
#include "projectile.h"
#include "scene_manager.h"

Gun::Gun()
    : _level(7) {}

void Gun::upgrade() {
	if (_level < 7) {
		_level++;
	}
}

const int SPREAD = 7;
const int SPEED = 250;
void Gun::shoot(Vector2 position) {
	Game* context = static_cast<Game*>(SceneManager::getInstance().getCurrentScene());
	Vector2 velocity(0, -SPEED);

	if (_level == 0 || _level == 2) {
		context->addEntity(new Projectile(position - Vector2(0, 5), velocity, PLAYER));
	}
	if (_level == 1 || _level == 2) {
		context->addEntity(new Projectile(position - Vector2(5, 0), velocity, PLAYER));
		context->addEntity(new Projectile(position + Vector2(6, 0), velocity, PLAYER));
	}
	if (_level > 2) {
		velocity = velocity.rotate(-SPREAD * (_level - 1) / 2);
		for (int i = 0; i < _level; i++) {
			context->addEntity(new Projectile(position - Vector2(0, 5), velocity, PLAYER));
			velocity = velocity.rotate(SPREAD);
		}
	}
}
