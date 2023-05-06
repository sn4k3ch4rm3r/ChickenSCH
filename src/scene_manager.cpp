#include "scene_manager.h"
#include <chrono>
#include "game.h"
#include "scene.h"

#ifndef CPORTA
#include "sdl_presentation.h"
#else
#include "jporta_presentation.h"
#endif

SceneManager SceneManager::_instance;
SceneManager& SceneManager::getInstance() {
	return _instance;
}

SceneManager::SceneManager()
    : _size(320, 180), _currentScene(nullptr), _deltaTime(std::chrono::nanoseconds(0)), _lastTime(std::chrono::high_resolution_clock::now()), _presentation(nullptr) {
#ifndef CPORTA
	_presentation = new SDLPresentation("ChickenSCH", _size.getWidth(), _size.getHeight());
#else
	_presentation = new JPortaPresentation("ChickenSCH", _size.getWidth(), _size.getHeight());
#endif
	_currentScene = new Game();
}

SceneManager::~SceneManager() {
	delete _presentation;
	delete _currentScene;
}

void SceneManager::update() {
	_deltaTime = std::chrono::nanoseconds(std::chrono::high_resolution_clock::now() - _lastTime);
	_lastTime = std::chrono::high_resolution_clock::now();
	_currentScene->update();
	Scene* _nextScene = _currentScene->nextScene();
	if (_nextScene != _currentScene) {
		delete _currentScene;
	}
	_currentScene = _nextScene;
}

void SceneManager::render() {
	_currentScene->render();
}

void SceneManager::handleEvents() {
	_presentation->handleEvents();
}

double SceneManager::getDeltaTime() const {
	return std::chrono::duration_cast<std::chrono::duration<double>>(_deltaTime).count();
}