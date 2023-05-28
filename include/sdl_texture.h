#ifndef SDL_TEXTURE_H
#define SDL_TEXTURE_H

#include <SDL.h>
#include "texture.h"
#include "vector2.h"

/// @brief SDL megjelenítéshez használt textúra.
class SDLTexture : public Texture {
public:
	explicit SDLTexture(SDL_Texture* texture)
	    : _texture(texture) {}
	~SDLTexture() { SDL_DestroyTexture(_texture); }
	SDL_Texture* getTexture() const { return _texture; }
	Size getSize() const override {
		int width, height;
		SDL_QueryTexture(_texture, NULL, NULL, &width, &height);
		return Size(width, height);
	}

private:
	SDL_Texture* _texture;
};

#endif