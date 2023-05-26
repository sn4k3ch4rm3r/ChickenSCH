#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "texture.h"
#include "vector2.h"

enum CollisionTag {
	NONE,
	PLAYER,
	ENEMY,
	POWERUP
};

class GameObject {
public:
	GameObject();
	explicit GameObject(const Vector2& position, CollisionTag tag = NONE, int health = 1);
	virtual ~GameObject();

	virtual void render();
	virtual void update();

	Vector2 getPosition() const;
	void setPosition(const Vector2& position);
	Vector2 getVelocity() const;
	void setVelocity(const Vector2& velocity);
	virtual bool checkCollision(const GameObject* other) const;
	virtual void onCollision(const GameObject* other);
	virtual Size getSize() const { return _texture->getSize(); }
	CollisionTag getTag() const { return _tag; }
	void setTag(CollisionTag tag) { _tag = tag; }
	virtual bool isProjectile() const { return false; }
	bool isAlive() const { return _health > 0; }
	int getHealth() const { return _health; }
	void setTexture(Texture* texture);
	Texture* getTexture() const { return _texture; }

private:
	Vector2 _position;
	Vector2 _velocity;
	Texture* _texture;
	int _health;
	CollisionTag _tag;
};

#endif