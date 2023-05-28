#ifndef GUN_H
#define GUN_H

#include "vector2.h"

class Gun {
public:
	Gun();

	/// @brief Lövés, ilyenkor a lövedékek a játék objektumok listájához adódnak.
	/// @param position A lövedék kiindulási pozíciója.
	void shoot(Vector2 position);

	/// @brief A fegyver szintjének növelése.
	void upgrade();

	/// @brief A fegyver szintjének viszaállítása az alapértelmezettre.
	void reset();

private:
	int _level;
};

#endif