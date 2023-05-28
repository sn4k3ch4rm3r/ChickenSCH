#ifndef CHICKENS_H
#define CHICKENS_H

#include "game_object.h"

/// @brief Csirkékhez tartozó állandók.
namespace ChickenConstants {
/// @brief Tojás valószínűsége minden frame-n.
const double EGG_PROBABILITY = 0.0005;

/// @brief Powerup létrejöttének valószínűsége.
const double POWERUP_PROBABILITY = 0.01;

/// @brief A csirkék alap sebessége az X tengelyen.
const int BASE_VELOCITY_X = 50;

/// @brief A csirkék alap sebessége az Y tengelyen.
const int BASE_VELOCITY_Y = 10;

/// @brief A csirkék sebességének növekedése szintenként.
const double SPEED_INCREASE = 2;

/// @brief Tojás valószínűségének növekedése szintenként.
const double EGG_INCREASE = 0.0001;

/// @brief A 2. szint csirkéinek sebesség eltérése.
const double SPEED_VARIATION = 0.4;
}  // namespace ChickenConstants

/// @brief Az irányok felsorolása.
enum Direction {
	LEFT = -1,
	RIGHT = 1
};

/// @brief A csirke osztály.
class Chicken : public GameObject {
public:
	/// @brief A csirke konstruktora.
	/// @param position A csirke pozíciója.
	/// @param health A csirke életereje.
	Chicken(const Vector2& position, int health);

	/// @brief A csirke frissítése.
	virtual void update() override;

	/// @brief A csirke ütközésének kezelése.
	/// @param other A másik játékobjektum.
	void onCollision(const GameObject* other) override;

	/// @brief A csirke tojásának valószínűségének lekérdezése.
	/// @return A csirke tojásának valószínűsége.
	double getEggProbability() const { return _eggProbability; }

	/// @brief A csirke irányának lekérdezése.
	/// @return A csirke iránya.
	Direction getDirection() const { return _direction; }

	/// @brief A csirke irányának beállítása.
	/// @param direction Az új irány.
	void setDirection(Direction direction) { _direction = direction; }

private:
	double _eggProbability;
	Direction _direction;
};

/// @brief 1. és 2. szinthez tartózó csirke.
class OrderedChicken : public Chicken {
public:
	OrderedChicken(const Vector2& position, int health);
	void update() override;

private:
	int _startingX;
};

/// @brief 3. szinthez tartozó csirke.
class RandomChicken : public Chicken {
public:
	RandomChicken(const Vector2& position, int health);
	void update() override;
};

/// @brief 4. szinthez tartozó csirke.
class DescendingChicken : public Chicken {
public:
	DescendingChicken(const Vector2& position, int health);
	void update() override;

private:
	int _startingX;
};

#endif