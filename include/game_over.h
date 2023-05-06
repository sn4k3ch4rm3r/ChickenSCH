#ifndef GAME_OVER_H
#define GAME_OVER_H

#include "scene.h"

class GameOver : public Scene {
public:
	GameOver();
	~GameOver();

	void update() override;
	void render() override;
};

#endif