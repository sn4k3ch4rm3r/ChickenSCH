#include "game_object.h"
#include "game.h"
#include "vector2.h"

GameObject::GameObject()
    : _position(0, 0), _velocity(0, 0), _texture(nullptr) {}

void GameObject::update() {
	_position += _velocity * Game::getInstance().getDeltaTime();
}

Vector2 GameObject::getPosition() const {
	return _position;
}

void GameObject::setPosition(const Vector2& position) {
	this->_position = position;
}

Vector2 GameObject::getVelocity() const {
	return _velocity;
}

void GameObject::setVelocity(const Vector2& velocity) {
	this->_velocity = velocity;
}

void GameObject::render() {
	Game::getInstance().getPresentation()->renderTexture(_texture, Vector2(_position.getX() - _texture->getSize().width / 2, _position.getY() - _texture->getSize().height / 2));
}
