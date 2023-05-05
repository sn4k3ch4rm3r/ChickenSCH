#ifndef JPORTA_INPUT_PROVIDER_H
#define JPORTA_INPUT_PROVIDER_H

#include "input_provider.h"
#include "vector2.h"

class JPortaInputProvider : public InputProvider {
public:
	Vector2 getMovementDirection() const override;
};

#endif