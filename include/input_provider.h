#ifndef INPUT_PROVIDER_H
#define INPUT_PROVIDER_H

#include "vector2.h"

enum InputMode {
	GAME,
	TEXTBOX
};

class InputProvider {
public:
	virtual ~InputProvider() {}
	virtual void handleEvent(void* event) = 0;
	virtual Vector2 getMovementDirection() const = 0;
	virtual bool isShooting() = 0;
	virtual void setCanShoot(bool canShoot) = 0;
	virtual void setInputMode(InputMode mode) = 0;
	virtual char* getInputText() = 0;
	virtual void clearInputText() = 0;
	virtual bool isInputReady() = 0;
};

#endif