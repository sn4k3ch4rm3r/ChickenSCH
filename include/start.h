#ifndef MENU_H
#define MENU_H

#include "leaderboard.h"
#include "scene.h"

class Start : public Scene {
public:
	Start();
	~Start();

	void update() override;
	void render() override;
};

#endif