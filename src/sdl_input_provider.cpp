#include "sdl_input_provider.h"
#include <SDL.h>
#include "vector2.h"

Vector2 SDLInputProvider::getMovementDirection() const {
	int dir = 0;
	const Uint8* state = SDL_GetKeyboardState(NULL);
	if (state[SDL_SCANCODE_A]) {
		dir -= 1;
	}
	if (state[SDL_SCANCODE_D]) {
		dir += 1;
	}
	return Vector2(dir, 0);
}
