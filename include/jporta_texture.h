#ifndef JPORTA_TEXTURE_H
#define JPORTA_TEXTURE_H

#include "texture.h"

class JPortaTexture : public Texture {
public:
	Size getSize() const override;
};
#endif