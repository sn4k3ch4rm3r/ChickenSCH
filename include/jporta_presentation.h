#ifndef JPORTA_PRESENTATION_H
#define JPORTA_PRESENTATION_H

#include "presentation.h"
#include "texture.h"
#include "vector2.h"

class JPortaPresentation : public IPresentation {
public:
	JPortaPresentation(const char* title, int width, int height);
	~JPortaPresentation();

	Texture* loadTexture(const char* path) override;
	void renderTexture(const Texture* texture, const Vector2& position) override;
	void renderText(const char* text, const Vector2& position) override;
	void clearScreen() override;
	void renderScreen() override;
	void handleEvents() override;
	bool isRunning() override;
	InputProvider* getInputProvider() override;

private:
	InputProvider* _inputProvider;
	bool _isRunning;
};

#endif