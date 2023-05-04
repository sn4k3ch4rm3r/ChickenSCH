#ifndef TEXTURE_H
#define TEXTURE_H

#include <SDL.h>

struct Size {
	int width;
	int height;
};

class Texture {
public:
	virtual ~Texture() {}
	virtual Size getSize() const { return _size; }

private:
	Size _size;
};

// TODO: Move this to a separate file
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