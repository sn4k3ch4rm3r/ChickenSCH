#ifndef SDL_TEXTURE_H
#define SDL_TEXTURE_H

#include <SDL.h>
#include "texture.h"

class SDLTexture : public Texture {
public:
	SDLTexture(SDL_Texture* texture)
	    : _texture(texture) {}
	~SDLTexture() { SDL_DestroyTexture(_texture); }
	SDL_Texture* const getTexture() const { return _texture; }
	Size getSize() const override {
		Size size;
		SDL_QueryTexture(_texture, NULL, NULL, &size.width, &size.height);
		return size;
	}

private:
	SDL_Texture* _texture;
};

#endif