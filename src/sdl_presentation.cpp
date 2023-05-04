#include "sdl_presentation.h"
#include <SDL.h>
#include <SDL_Image.h>
#include "sdl_input_provider.h"

SDLPresentationFacade::SDLPresentationFacade(const char* title, int width, int height) {
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		std::cerr << "Error while initializing SDL: " << SDL_GetError() << std::endl;
	}

	_window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width * 4, height * 4, SDL_WINDOW_SHOWN);
	if (_window == NULL) {
		std::cerr << "Error while creating window: " << SDL_GetError() << std::endl;
	}

	_renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE | SDL_RENDERER_PRESENTVSYNC);
	if (_renderer == NULL) {
		std::cerr << "Error while creating renderer: " << SDL_GetError() << std::endl;
	}

	// SDL_SetWindowFullscreen(_window, SDL_WINDOW_FULLSCREEN_DESKTOP);
	SDL_RenderSetLogicalSize(_renderer, width, height);

	_inputProvider = new SDLInputProvider();
}

SDLPresentationFacade::~SDLPresentationFacade() {
	SDL_DestroyRenderer(_renderer);
	SDL_DestroyWindow(_window);
}

void SDLPresentationFacade::renderTexture(const Texture* texture, const Vector2& position) {
	SDL_Rect destination;
	destination.x = position.getX();
	destination.y = position.getY();
	Size size = texture->getSize();
	destination.w = size.width;
	destination.h = size.height;
	SDL_RenderCopy(_renderer, dynamic_cast<const SDLTexture*>(texture)->getTexture(), NULL, &destination);
}

Texture* SDLPresentationFacade::loadTexture(const char* path) {
	SDL_Surface* surface = IMG_Load(path);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(_renderer, surface);
	SDL_FreeSurface(surface);
	return new SDLTexture(texture);
}

void SDLPresentationFacade::clearScreen() {
	SDL_RenderClear(_renderer);
}

void SDLPresentationFacade::renderScreen() {
	SDL_RenderPresent(_renderer);
}

void SDLPresentationFacade::exit() {
	SDL_Quit();
}

void SDLPresentationFacade::handleEvents() {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT) {
			_isRunning = false;
		}
	}
}

bool SDLPresentationFacade::isRunning() {
	return _isRunning;
}

InputProvider* SDLPresentationFacade::getInputProvider() {
	return _inputProvider;
}