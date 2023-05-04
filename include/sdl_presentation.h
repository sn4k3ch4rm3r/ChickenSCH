#ifndef SDL_INTERFACE_H
#define SDL_INTERFACE_H

#include <SDL.h>
#include <string>
#include "presentation.h"
#include "texture.h"
#include "vector2.h"

class SDLPresentationFacade : public IPresentationFacade {
public:
	SDLPresentationFacade(const char* title, int width, int height);
	~SDLPresentationFacade();

	Texture* loadTexture(const char* path) override;
	void renderTexture(const Texture* texture, const Vector2& position) override;
	void clearScreen() override;
	void renderScreen() override;
	void exit() override;
	void handleEvents() override;
	bool isRunning() override;
	InputProvider* getInputProvider() override;

private:
	SDL_Window* _window;
	SDL_Renderer* _renderer;
	InputProvider* _inputProvider;
	bool _isRunning;
};

#endif