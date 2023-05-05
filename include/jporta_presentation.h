#ifndef JPORTA_PRESENTATION_H
#define JPORTA_PRESENTATION_H

#include "presentation.h"
#include "texture.h"
#include "vector2.h"

class JPortaPresentationFacade : public IPresentationFacade {
public:
	JPortaPresentationFacade(const char* title, int width, int height);
	~JPortaPresentationFacade();

	Texture* loadTexture(const char* path) override;
	void renderTexture(const Texture* texture, const Vector2& position) override;
	void clearScreen() override;
	void renderScreen() override;
	void exit() override;
	void handleEvents() override;
	bool isRunning() override;
	InputProvider* getInputProvider() override;
};

#endif