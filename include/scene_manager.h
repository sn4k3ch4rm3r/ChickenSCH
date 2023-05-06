#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H

#include <chrono>
#include "presentation.h"
#include "scene.h"
#include "vector2.h"

class SceneManager {
public:
	static SceneManager& getInstance();
	SceneManager(const SceneManager&) = delete;
	SceneManager& operator=(const SceneManager&) = delete;
	~SceneManager();

	void update();
	void render();
	void handleEvents();

	double getDeltaTime() const;
	IPresentation* getPresentation() const { return _presentation; }
	bool isRunning() const { return _presentation->isRunning(); }
	Size getSize() const { return _size; }

private:
	SceneManager();
	static SceneManager _instance;

	Size _size;
	Scene* _currentScene;
	std::chrono::nanoseconds _deltaTime;
	std::chrono::time_point<std::chrono::high_resolution_clock> _lastTime;

	IPresentation* _presentation;
};

#endif