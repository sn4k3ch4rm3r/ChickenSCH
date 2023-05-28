#ifndef MENU_H
#define MENU_H

#include "leaderboard.h"
#include "scene.h"
#include "texture.h"

/// @brief A kezdő képernyő.
class Start : public Scene {
public:
	Start();
	~Start();

	/// @brief A képernyő frissítése.
	void update() override;

	/// @brief A képernyő kirajzolása.
	void render() override;

private:
	Texture* _titleText;
};

#endif