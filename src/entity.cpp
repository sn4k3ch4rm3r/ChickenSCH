#include "entity.h"
#include "game.h"
#include "vector2.h"

Entity::Entity()
    : _position(0, 0), _velocity(0, 0), _texture(nullptr) {}

void Entity::update() {
	_position += _velocity * Game::getInstance().getDeltaTime();
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
	Game::getInstance().getPresentation()->renderTexture(_texture, Vector2(_position.getX() - _texture->getSize().width / 2, _position.getY() - _texture->getSize().height / 2));
}
