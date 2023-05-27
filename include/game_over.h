#ifndef GAME_OVER_H
#define GAME_OVER_H

#include "leaderboard.h"
#include "scene.h"

class GameOver : public Scene {
public:
	explicit GameOver(int score);
	~GameOver();

	void update() override;
	void render() override;

private:
	LeaderBoardItem _leaderBoardItem;
	Texture* _gameOverText;
	Texture* _textbox;
};

#endif