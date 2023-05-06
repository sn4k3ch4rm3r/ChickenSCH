#ifndef SDL_INPUT_PROVIDER_H
#define SDL_INPUT_PROVIDER_H

#include "input_provider.h"
#include "vector2.h"

class SDLInputProvider : public InputProvider {
public:
	SDLInputProvider()
	    : _canShoot(true){};

	Vector2 getMovementDirection() const override;
	bool isShooting() override;
	void setCanShoot(bool canShoot) override;

private:
	bool _canShoot;
};

#endif