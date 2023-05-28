#ifndef GAME_OVER_H
#define GAME_OVER_H

#include "leaderboard.h"
#include "scene.h"

class GameOver : public Scene {
public:
	/// @brief A game over képernyő konstruktora.
	/// @param score A játékban elért pontszám, a ranglistára mentéshez van szükség rá.
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