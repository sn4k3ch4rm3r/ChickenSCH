#ifndef INPUT_PROVIDER_H
#define INPUT_PROVIDER_H

#include "vector2.h"

/// @brief A játék input módjai
/// @details A két input mód a játék és a szövegbevitel.
enum InputMode {
	GAME,
	TEXTBOX
};

/// @brief Az inputot biztosító osztály interfésze.
class InputProvider {
public:
	virtual ~InputProvider() {}

	/// @brief Az események kezelése.
	/// @param event A kezelni kívánt esemény.
	/// @details Azért void*, mert a konkrét események típusa a platformfüggő kódban van.
	virtual void handleEvent(void* event) = 0;

	/// @brief A mozgás irányának lekérdezése.
	/// @return A mozgás iránya.
	virtual Vector2 getMovementDirection() const = 0;

	/// @brief Lövési szándék lekérdezése.
	/// @return Éppen lő-e a játékos.
	virtual bool isShooting() = 0;

	/// @brief Lövés engedélyezése.
	/// @param canShoot Engedélyezett-e a lövés.
	virtual void setCanShoot(bool canShoot) = 0;

	/// @brief A játék input módjának beállítása.
	/// @param mode Általában GAME, ha a játékban vagyunk, TEXTBOX, ha a szövegbevitelben.
	virtual void setInputMode(InputMode mode) = 0;

	/// @brief A szövegbevitelben lévő szöveg lekérdezése.
	/// @return A szövegbevitelben lévő szöveg.
	virtual char* getInputText() = 0;

	/// @brief A szövegbevitelben lévő szöveg törlése.
	virtual void clearInputText() = 0;

	/// @brief Végeztünk-e a szövegbevitellel.
	/// @return Igaz, ha végeztünk, egyébként hamis.
	virtual bool isInputReady() = 0;
};

#endif