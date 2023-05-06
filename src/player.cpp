#include "player.h"
#include "game.h"
#include "scene_manager.h"

Player::Player(int x, int y)
    : GameObject() {
	_texture = SceneManager::getInstance().getPresentation()->loadTexture("assets/ship.png");
	_position = Vector2(x, y);
}

void Player::update() {

	_velocity = SceneManager::getInstance().getPresentation()->getInputProvider()->getMovementDirection() * 200;

	GameObject::update();
}