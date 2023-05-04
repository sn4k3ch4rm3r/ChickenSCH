#ifndef ENTITY_H
#define ENTITY_H

#include "texture.h"
#include "vector2.h"

class Entity {

public:
	Entity();
	virtual ~Entity(){};

	virtual void render();
	virtual void update();

	Vector2 getPosition() const;
	void setPosition(const Vector2& position);
	Vector2 getVelocity() const;
	void setVelocity(const Vector2& velocity);

protected:
	Vector2 _position;
	Vector2 _velocity;
	Texture* _texture;
};

#endif