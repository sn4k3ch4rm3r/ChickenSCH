#include "entity.h"
#include "game.h"
#include "vector2.h"

void Entity::update() {
	position += velocity * Game::deltaTime;
}

Vector2 Entity::getPosition() const {
	return position;
}

void Entity::setPosition(const Vector2& position) {
	this->position = position;
}

Vector2 Entity::getVelocity() const {
	return velocity;
}

void Entity::setVelocity(const Vector2& velocity) {
	this->velocity = velocity;
}