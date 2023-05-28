#ifndef JPORTA_INPUT_PROVIDER_H
#define JPORTA_INPUT_PROVIDER_H

#include "input_provider.h"
#include "vector2.h"

class JportaInputProvider : public InputProvider {
public:
	JportaInputProvider()
	    : _inputMode(GAME), _inputReady(true), _inputText(""), _canShoot(true){};

	Vector2 getMovementDirection() const override;
	bool isShooting() override;
	void setCanShoot(bool canShoot) override;
	void setInputMode(InputMode mode) override;
	char* getInputText() override;
	void clearInputText() override;
	void handleEvent(void* event) override;
	bool isInputReady() override;

private:
	InputMode _inputMode;
	bool _inputReady;
	char _inputText[20];
	bool _canShoot;
};

#endif