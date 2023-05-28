#ifndef CPORTA

#include "sdl_input_provider.h"
#include <SDL.h>
#include <cstring>
#include "vector2.h"

Vector2 SDLInputProvider::getMovementDirection() const {
	int dir = 0;
	const Uint8* state = SDL_GetKeyboardState(nullptr);
	if (state[SDL_SCANCODE_A]) {
		dir -= 1;
	}
	if (state[SDL_SCANCODE_D]) {
		dir += 1;
	}
	return Vector2(dir, 0);
}

auto SDLInputProvider::isShooting() -> bool {
	const Uint8* state = SDL_GetKeyboardState(nullptr);
	bool trying = state[SDL_SCANCODE_SPACE] != 0;
	if (trying && _canShoot) {
		_canShoot = false;
		return true;
	}
	return false;
}

void SDLInputProvider::handleEvent(void* event) {
	SDL_Event& e = *static_cast<SDL_Event*>(event);
	switch (_inputMode) {
		case GAME:
			if (e.type == SDL_KEYUP && e.key.keysym.sym == SDLK_SPACE) {
				_canShoot = true;
			}
			break;
		case TEXTBOX:
			if (e.type == SDL_KEYDOWN) {
				if (e.key.keysym.sym == SDLK_BACKSPACE) {
					int len = strlen(_inputText);
					if (len > 0) {
						_inputText[len - 1] = '\0';
					}
				}
				else if (e.key.keysym.sym == SDLK_RETURN) {
					_inputReady = true;
					setInputMode(GAME);
				}
			}
			else if (e.type == SDL_TEXTINPUT) {
				int len = strlen(_inputText);
				size_t i;
				for (i = 0; i < strlen(e.text.text) && len + i < 20; i++) {
					if (isalnum(e.text.text[i])) {
						_inputText[len + i] = e.text.text[i];
					}
				}
				_inputText[len + i] = '\0';
			}
			break;
	}
}

void SDLInputProvider::setCanShoot(bool canShoot) {
	_canShoot = canShoot;
}

void SDLInputProvider::setInputMode(InputMode mode) {
	_inputMode = mode;
	if (mode == TEXTBOX) {
		_inputReady = false;
		clearInputText();
		SDL_StartTextInput();
	}
	else {
		SDL_StopTextInput();
	}
}

char* SDLInputProvider::getInputText() {
	return _inputText;
}

void SDLInputProvider::clearInputText() {
	_inputText[0] = '\0';
}

bool SDLInputProvider::isInputReady() {
	return _inputReady;
}

#endif