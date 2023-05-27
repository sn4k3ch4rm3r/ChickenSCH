#include "game_over.h"
#include "scene_manager.h"
#include "start.h"

GameOver::GameOver(int score) {
	_leaderBoardItem.score = score;
	_leaderBoardItem.name[0] = '\0';
	_gameOverText = SceneManager::getInstance().getPresentation()->loadTexture("assets/game_over.png");
	_textbox = SceneManager::getInstance().getPresentation()->loadTexture("assets/textbox.png");
}

GameOver::~GameOver() {
	delete _gameOverText;
	delete _textbox;
}

void GameOver::update() {}

void GameOver::render() {
	IPresentation* presentation = SceneManager::getInstance().getPresentation();
	presentation->renderTexture(_gameOverText, Vector2(75, 15));
	presentation->renderText(
	    ("Your score: " + std::to_string(_leaderBoardItem.score)).c_str(),
	    Vector2(110, 130)
	);
	presentation->renderText("Enter your name:", Vector2(110, 150));
	presentation->renderTexture(_textbox, Vector2(110, 170));
	presentation->renderText(_leaderBoardItem.name, Vector2(120, 178));
	presentation->renderText("Press [ENTER] to continue", Vector2(105, 270));
}