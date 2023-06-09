#ifndef SDL_INTERFACE_H
#define SDL_INTERFACE_H

#include <SDL.h>
#include <string>
#include "presentation.h"
#include "texture.h"
#include "vector2.h"

/// @brief SDL alapú megjelenítési felület.
class SDLPresentation : public IPresentation {
public:
	SDLPresentation(const char* title, int width, int height);
	~SDLPresentation();

	SDLPresentation(const SDLPresentation&) = delete;
	SDLPresentation& operator=(const SDLPresentation&) = delete;

	Texture* loadTexture(const char* path) override;
	void renderTexture(const Texture* texture, const Vector2& position) override;
	void renderText(const char* text, const Vector2& position) override;
	void clearScreen() override;
	void renderScreen() override;
	void handleEvents() override;
	bool isRunning() override;
	InputProvider* getInputProvider() override;

private:
	InputProvider* _inputProvider;
	bool _isRunning;
	SDL_Window* _window;
	SDL_Renderer* _renderer;
};

#endif