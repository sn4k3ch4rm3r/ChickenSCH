#ifndef SDL_INPUT_PROVIDER_H
#define SDL_INPUT_PROVIDER_H

#include <SDL.h>
#include "input_provider.h"
#include "vector2.h"

/// @brief SDL alapú bemenetkezelő.
class SDLInputProvider : public InputProvider {
public:
	SDLInputProvider()
	    : _inputMode(GAME), _inputReady(true), _inputText(""), _canShoot(true){};

	Vector2 getMovementDirection() const override;
	bool isShooting() override;
	void setInputMode(InputMode mode) override;
	char* getInputText() override;
	void clearInputText() override;
	void handleEvent(void* event) override;
	bool isInputReady() override;

private:
	InputMode _inputMode;
	bool _inputReady;
	char _inputText[20];
	bool _canShoot;
};

#endif