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
	virtual Size getSize() const;
};

#endif