#ifndef BASE_INTERFACE_H
#define BASE_INTERFACE_H

#include <string>
#include "input_provider.h"
#include "texture.h"
#include "vector2.h"

class IPresentationFacade {
public:
	virtual ~IPresentationFacade() {}

	virtual Texture* loadTexture(const char* path) = 0;
	virtual void renderTexture(const Texture* texture, const Vector2& position) = 0;
	virtual void clearScreen() = 0;
	virtual void renderScreen() = 0;
	virtual void exit() = 0;
	virtual void handleEvents() = 0;
	virtual bool isRunning() = 0;
	virtual InputProvider* getInputProvider() = 0;
};

#endif