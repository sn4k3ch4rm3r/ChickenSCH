#include "game_over.h"
#include <cstring>
#include "leaderboard.h"
#include "scene_manager.h"
#include "start.h"

GameOver::GameOver(int score) {
	_leaderBoardItem.score = score;
	_leaderBoardItem.name[0] = '\0';
	_gameOverText = SceneManager::getInstance().getPresentation()->loadTexture("assets/game_over.png");
	_textbox = SceneManager::getInstance().getPresentation()->loadTexture("assets/textbox.png");
	SceneManager::getInstance().getPresentation()->getInputProvider()->setInputMode(TEXTBOX);
}

GameOver::~GameOver() {
	delete _gameOverText;
	delete _textbox;
}

void GameOver::update() {
	SceneManager& context = SceneManager::getInstance();
	strcpy_s(_leaderBoardItem.name, 20 * sizeof(char), context.getPresentation()->getInputProvider()->getInputText());
	if (context.getPresentation()->getInputProvider()->isInputReady()) {
		if (strlen(_leaderBoardItem.name) > 0) {
			LeaderBoardItem* item = new LeaderBoardItem();
			strcpy_s(item->name, 20 * sizeof(char), _leaderBoardItem.name);
			item->score = _leaderBoardItem.score;
			context.getLeaderBoard().addScore(item);
		}
		context.setCurrentScene(new Start());
	}
}

void GameOver::render() {
	auto presentation = SceneManager::getInstance().getPresentation();
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