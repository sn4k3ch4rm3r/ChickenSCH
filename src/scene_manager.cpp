#include "scene_manager.h"
#include <chrono>
#include "scene.h"
#include "start.h"

#ifndef CPORTA
#include "sdl_presentation.h"
#else
#include "jporta_presentation.h"
#endif
#include "memtrace.h"

SceneManager SceneManager::_instance;
SceneManager& SceneManager::getInstance() {
	return _instance;
}

SceneManager::SceneManager()
    : _size(400, 300), _currentScene(nullptr), _deltaTime(std::chrono::nanoseconds(0)), _lastTime(std::chrono::high_resolution_clock::now()), _presentation(nullptr) {
#ifndef CPORTA
	_presentation = new SDLPresentation("ChickenSCH", _size.getWidth(), _size.getHeight());
#else
	_presentation = new JPortaPresentation("ChickenSCH", _size.getWidth(), _size.getHeight());
#endif

	std::fstream file("leaderboard.csv", std::ios::in);
	_leaderBoard.loadScores(file);
	file.close();

	_currentScene = new Start();
}

SceneManager::~SceneManager() {
	std::fstream file("leaderboard.csv", std::ios::out);
	_leaderBoard.saveScores(file);
	file.close();

	delete _presentation;
	delete _currentScene;
}

void SceneManager::update() {
	_deltaTime = std::chrono::nanoseconds(std::chrono::high_resolution_clock::now() - _lastTime);
	_lastTime = std::chrono::high_resolution_clock::now();
	_currentScene->update();
}

void SceneManager::render() {
	_presentation->clearScreen();
	_currentScene->render();
	_presentation->renderScreen();
}

void SceneManager::handleEvents() {
	_presentation->handleEvents();
}

double SceneManager::getDeltaTime() const {
	return std::chrono::duration_cast<std::chrono::duration<double>>(_deltaTime).count();
}

void SceneManager::setCurrentScene(Scene* scene) {
	delete _currentScene;
	_currentScene = scene;
}