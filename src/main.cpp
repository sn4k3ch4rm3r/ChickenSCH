#include "scene_manager.h"

int main(int argc, char* argv[]) {

	SceneManager& scene_manager = SceneManager::getInstance();

	while (scene_manager.isRunning()) {
		scene_manager.handleEvents();
		scene_manager.update();
		scene_manager.render();
	}

	return 0;
}
