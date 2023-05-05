#ifndef TEXTURE_H
#define TEXTURE_H

#include "vector2.h"

class Texture {
public:
	virtual ~Texture() {}
	virtual Size getSize() const = 0;
};

#endif