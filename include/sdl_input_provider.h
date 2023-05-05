#ifndef SDL_INPUT_PROVIDER_H
#define SDL_INPUT_PROVIDER_H

#include "input_provider.h"
#include "vector2.h"

class SDLInputProvider : public InputProvider {
public:
	Vector2 getMovementDirection() const override;
};

#endif