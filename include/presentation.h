#ifndef BASE_INTERFACE_H
#define BASE_INTERFACE_H

#include <string>
#include "input_provider.h"
#include "texture.h"
#include "vector2.h"

/// @brief A játék megjelenítéséért felelős osztály interfésze.
/// @details A konkrét megjelenítési módokat a platformfüggő kódban kell implementálni.
class IPresentation {
public:
	virtual ~IPresentation() {}

	/// @brief PNG textura betöltése adott fájlból.
	/// @param path A fájl neve.
	/// @return Textúrára mutató pointer.
	virtual Texture* loadTexture(const char* path) = 0;

	/// @brief Textúra kirajzolása adott helyre.
	/// @param texture A kirajzolandó textúra.
	/// @param position A kirajzolás helye.
	virtual void renderTexture(const Texture* texture, const Vector2& position) = 0;

	/// @brief Szöveg kirajzolása adott helyre.
	/// @param text A kirajzolandó szöveg.
	/// @param position A kirajzolás helye.
	virtual void renderText(const char* text, const Vector2& position) = 0;

	/// @brief Képernyő törlése.
	virtual void clearScreen() = 0;

	/// @brief A képernyőn kirajzolt elemek megjelenítése.
	virtual void renderScreen() = 0;

	/// @brief Események kezelése.
	virtual void handleEvents() = 0;

	/// @brief A megjelnítő környezet futásának lekérdezése.
	/// @return Igaz, ha fut, egyébként hamis.
	virtual bool isRunning() = 0;

	/// @brief A bemenetet biztosító osztály lekérdezése.
	/// @return A bemenetet kezelőre mutató pointer.
	virtual InputProvider* getInputProvider() = 0;
};

#endif