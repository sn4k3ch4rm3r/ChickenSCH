#include "jporta_presentation.h"

JPortaPresentation::JPortaPresentation(const char* title, int width, int height)
    : _inputProvider(nullptr), _isRunning(false) {
}

JPortaPresentation::~JPortaPresentation() {
}

Texture* JPortaPresentation::loadTexture(const char* path) {
	return nullptr;
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