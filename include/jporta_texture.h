#ifndef JPORTA_TEXTURE_H
#define JPORTA_TEXTURE_H

#include "texture.h"
#include "vector2.h"

class JPortaTexture : public Texture {
public:
	Size getSize() const override { return Size(0, 0); };
};
#endif