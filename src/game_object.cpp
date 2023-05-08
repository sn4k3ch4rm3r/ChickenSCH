#include "game_object.h"
#include "game.h"
#include "scene_manager.h"
#include "vector2.h"

GameObject::GameObject()
    : _position(0, 0), _velocity(0, 0), _texture(nullptr), _health(1) {}

GameObject::GameObject(const Vector2& position)
    : GameObject() {
	_position = position;
}

GameObject::~GameObject() {
	delete _texture;
}

void GameObject::update() {
	_position += _velocity * SceneManager::getInstance().getDeltaTime();
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
	SceneManager::getInstance().getPresentation()->renderTexture(_texture, _position - (_texture->getSize() / 2));
}

bool GameObject::checkCollision(const GameObject* other) const {
	Vector2 thisMin = _position - (getSize() / 2);
	Vector2 thisMax = _position + (getSize() / 2);
	Vector2 otherMin = other->getPosition() - (other->getSize() / 2);
	Vector2 otherMax = other->getPosition() + (other->getSize() / 2);

	bool overlaps = thisMin.getX() < otherMax.getX() && thisMax.getX() > otherMin.getX() &&
	                thisMin.getY() < otherMax.getY() && thisMax.getY() > otherMin.getY();
	return overlaps && _tag != other->getTag();
}

void GameObject::onCollision(const GameObject* other) {
	if (other->getTag() != POWERUP) {
		_health--;
	}
}