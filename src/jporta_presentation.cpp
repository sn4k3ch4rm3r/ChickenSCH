#include "jporta_presentation.h"
#include "jporta_input_provider.h"
#include "jporta_texture.h"
#include "memtrace.h"

JPortaPresentation::JPortaPresentation(const char* title, int width, int height)
    : _inputProvider(new JportaInputProvider()), _isRunning(false) {
}

JPortaPresentation::~JPortaPresentation() {
	delete _inputProvider;
}

Texture* JPortaPresentation::loadTexture(const char* path) {
	return new JPortaTexture();
}

void JPortaPresentation::renderTexture(const Texture* texture, const Vector2& position) {
}

void JPortaPresentation::renderText(const char* text, const Vector2& position) {
}

void JPortaPresentation::clearScreen() {
}

void JPortaPresentation::renderScreen() {
}

void JPortaPresentation::handleEvents() {
}

bool JPortaPresentation::isRunning() {
	return _isRunning;
}

InputProvider* JPortaPresentation::getInputProvider() {
	return _inputProvider;
}