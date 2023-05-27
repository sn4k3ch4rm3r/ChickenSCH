#include "start.h"
#include "game.h"
#include "leaderboard.h"
#include "scene_manager.h"

Start::Start() {
	_titleText = SceneManager::getInstance().getPresentation()->loadTexture("assets/title.png");
}

Start::~Start() {
	delete _titleText;
}

void Start::update() {
	SceneManager& sceneManager = SceneManager::getInstance();
	if (sceneManager.getPresentation()->getInputProvider()->isShooting()) {
		sceneManager.setCurrentScene(new Game());
	}
}

void Start::render() {
	SceneManager::getInstance().getPresentation()->renderTexture(_titleText, Vector2(100, 15));
	SceneManager::getInstance().getLeaderBoard().render();
	SceneManager::getInstance().getPresentation()->renderText("Press [SPACE] to start", Vector2(110, 270));
}
