#include "m_random.h"
#include "scene_manager.h"
#include "memtrace.h"

int main() {
	Random::seed();
	SceneManager& sceneManager = SceneManager::getInstance();

	while (sceneManager.isRunning()) {
		sceneManager.handleEvents();
		sceneManager.update();
		sceneManager.render();
	}

	return 0;
}
