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
	// std::cout << _texture->getSize() / 2 << std::endl;
	Game::getInstance().getPresentation()->renderTexture(_texture, _position - (_texture->getSize() / 2));
}
