#include "jporta_input_provider.h"
#include "vector2.h"

Vector2 JportaInputProvider::getMovementDirection() const {
	return Vector2(0, 0);
}

bool JportaInputProvider::isShooting() {
	return false;
}

void JportaInputProvider::setCanShoot(bool canShoot) {
	_canShoot = canShoot;
}

void JportaInputProvider::setInputMode(InputMode mode) {
	_inputMode = mode;
}

char* JportaInputProvider::getInputText() {
	return _inputText;
}

void JportaInputProvider::clearInputText() {
	_inputText[0] = '\0';
}

void JportaInputProvider::handleEvent(void* event) {
}

bool JportaInputProvider::isInputReady() {
	return _inputReady;
}