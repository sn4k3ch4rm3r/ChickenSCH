#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "texture.h"
#include "vector2.h"

/// @brief Az ütközési címkék felsorolása.
enum CollisionTag {
	NONE,
	PLAYER,
	ENEMY,
	POWERUP
};

/// @brief A játékban szereplő objektumok ősosztálya.
class GameObject {
public:
	/// @brief Alapértelmezett konstruktor.
	GameObject();

	/// @brief A játékobjektum konstruktora.
	/// @param position A játékobjektum pozíciója.
	/// @param tag Az ütközési címke.
	/// @param health Az életerő.
	explicit GameObject(const Vector2& position, CollisionTag tag = NONE, int health = 1);

	virtual ~GameObject();

	/// @brief A játékobjektum kirajzolása.
	virtual void render();

	/// @brief A játékobjektum frissítése.
	virtual void update();

	/// @brief A játékobjektum pozíciójának lekérdezése.
	/// @return A játékobjektum pozíciója.
	Vector2 getPosition() const;

	/// @brief A játékobjektum pozíciójának beállítása.
	/// @param position Az új pozíció.
	void setPosition(const Vector2& position);

	/// @brief A játékobjektum sebességének lekérdezése.
	/// @return A játékobjektum sebessége.
	Vector2 getVelocity() const;

	/// @brief A játékobjektum sebességének beállítása.
	/// @param velocity Az új sebesség.
	void setVelocity(const Vector2& velocity);

	/// @brief A játékobjektum ütközésének ellenőrzése.
	/// @param other A másik játékobjektum.
	/// @return Igaz, ha ütközik, egyébként hamis.
	virtual bool checkCollision(const GameObject* other) const;

	/// @brief Az ütközés kezelése.
	/// @param other A másik játékobjektum.
	virtual void onCollision(const GameObject* other);

	/// @brief A játékobjektum méretének lekérdezése.
	/// @return A játékobjektum mérete.
	virtual Size getSize() const { return _texture->getSize(); }

	/// @brief Az ütközési címke lekérdezése.
	/// @return Az ütközési címke.
	CollisionTag getTag() const { return _tag; }

	/// @brief Az ütközési címke beállítása.
	/// @param tag Az új ütközési címke.
	void setTag(CollisionTag tag) { _tag = tag; }

	/// @brief Ellenőrzi, hogy az objektum lövedék-e.
	/// @return Igaz, ha az objektum lövedék, egyébként hamis.
	virtual bool isProjectile() const { return false; }

	/// @brief Az objektum életben van-e.
	/// @return Igaz, ha az objektum életben van, egyébként hamis.
	bool isAlive() const { return _health > 0; }

	/// @brief Az objektum életerejének lekérdezése.
	/// @return Az objektum életereje.
	int getHealth() const { return _health; }

	/// @brief Az objektum textúrájának beállítása.
	/// @param texture Az új textúra.
	void setTexture(Texture* texture);

	/// @brief Az objektum textúrájának lekérdezése.
	/// @return Az objektum textúrája.
	Texture* getTexture() const { return _texture; }

private:
	Vector2 _position;
	Vector2 _velocity;
	Texture* _texture;
	int _health;
	CollisionTag _tag;
};

#endif