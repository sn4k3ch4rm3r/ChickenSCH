#include "player.h"
#include "game.h"

Player::Player()
    : Entity() {
	_texture = Game::presentation->loadTexture("assets/ship.png");
	_position = Vector2(160, 150);
}

void Player::update() {
	_velocity = Game::presentation->getInputProvider()->getMovementDirection() * 200;

	Entity::update();
}