#include "entity.h"
#include "game.h"
#include "vector2.h"

Entity::Entity()
    : _position(0, 0), _velocity(0, 0), _texture(nullptr) {}

void Entity::update() {
	_position += _velocity * Game::deltaTime;
}

Vector2 Entity::getPosition() const {
	return _position;
}

void Entity::setPosition(const Vector2& position) {
	this->_position = position;
}

Vector2 Entity::getVelocity() const {
	return _velocity;
}

void Entity::setVelocity(const Vector2& velocity) {
	this->_velocity = velocity;
}

void Entity::render() {
	Game::presentation->renderTexture(_texture, _position);
}
