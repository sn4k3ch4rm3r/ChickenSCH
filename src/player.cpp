#include "player.h"
#include "game.h"

Player::Player(int x, int y)
    : GameObject() {
	_texture = Game::getInstance().getPresentation()->loadTexture("assets/ship.png");
	_position = Vector2(x, y);
}

void Player::update() {

	_velocity = Game::getInstance().getPresentation()->getInputProvider()->getMovementDirection() * 200;

	GameObject::update();
}