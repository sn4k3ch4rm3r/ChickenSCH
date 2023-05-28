#include "chickens.h"
#include <cmath>
#include "game.h"
#include "game_object.h"
#include "m_random.h"
#include "projectile.h"
#include "scene_manager.h"

Chicken::Chicken(const Vector2& position, int health)
    : GameObject(position, ENEMY, health),
      _eggProbability(ChickenConstants::EGG_PROBABILITY + health * ChickenConstants::EGG_INCREASE),
      _direction(RIGHT) {}

void Chicken::update() {
	if (Random::randBool(getEggProbability())) {
		static_cast<Game*>(SceneManager::getInstance().getCurrentScene())->addEntity(new Projectile(getPosition(), Vector2(0, ProjectileConstants::EGG_VELOCITY), ENEMY));
	}
	setPosition(getPosition() + Vector2(getVelocity().getX() * _direction, getVelocity().getY()) * SceneManager::getInstance().getDeltaTime());
}

void Chicken::onCollision(const GameObject* other) {
	GameObject::onCollision(other);
	if (
	    getHealth() <= 0 &&
	    other->getTag() != POWERUP &&
	    Random::randBool(ChickenConstants::POWERUP_PROBABILITY)
	) {
		static_cast<Game*>(SceneManager::getInstance().getCurrentScene())->addEntity(new Projectile(getPosition(), Vector2(0, ProjectileConstants::POWERUP_VELOCITY), POWERUP));
	}
}

OrderedChicken::OrderedChicken(const Vector2& position, int health)
    : Chicken(position, health), _startingX(position.getX()) {
	setTexture(SceneManager::getInstance().getPresentation()->loadTexture(
	    "blue_chicken.png"
	));
	setVelocity(
	    Vector2(
	        ChickenConstants::BASE_VELOCITY_X + health * ChickenConstants::SPEED_INCREASE,
	        0
	    )
	);
}

void OrderedChicken::update() {
	if (getPosition().getX() - _startingX > 80) {
		setDirection(LEFT);
	}
	else if (getPosition().getX() - _startingX <= 0) {
		setDirection(RIGHT);
	}
	Chicken::update();
}

RandomChicken::RandomChicken(const Vector2& position, int health)
    : Chicken(position, health) {
	setTexture(SceneManager::getInstance().getPresentation()->loadTexture(
	    "pink_chicken.png"
	));
	setDirection(Random::randBool() ? LEFT : RIGHT);
	setVelocity(
	    Vector2(
	        ChickenConstants::BASE_VELOCITY_X * Random::randDouble(1 - ChickenConstants::SPEED_VARIATION, 1 + ChickenConstants::SPEED_VARIATION),
	        ChickenConstants::BASE_VELOCITY_Y
	    )
	);
}

void RandomChicken::update() {
	if (getPosition().getX() <= getSize().getWidth() / 2) {
		setDirection(RIGHT);
	}
	else if (getPosition().getX() >= SceneManager::getInstance().getSize().getWidth() - getSize().getWidth() / 2) {
		setDirection(LEFT);
	}
	Chicken::update();
}

DescendingChicken::DescendingChicken(const Vector2& position, int health)
    : Chicken(position, health), _startingX(position.getX()) {
	setTexture(SceneManager::getInstance().getPresentation()->loadTexture(
	    "green_chicken.png"
	));
	setVelocity(
	    Vector2(
	        ChickenConstants::BASE_VELOCITY_X + health * ChickenConstants::SPEED_INCREASE,
	        ChickenConstants::BASE_VELOCITY_Y
	    )
	);
}

void DescendingChicken::update() {
	if (getPosition().getX() - _startingX > 80) {
		setDirection(LEFT);
	}
	else if (getPosition().getX() - _startingX <= 0) {
		setDirection(RIGHT);
	}
	Chicken::update();
}