#ifndef GAME_H
#define GAME_H

#include <list>
#include <vector>
#include "game_object.h"
#include "levels.h"
#include "scene.h"

class Game : public Scene {
public:
	Game();
	~Game();

	/// @brief A játék kirajzolása.
	void render() override;

	/// @brief A játék frissítése.
	void update() override;

	/// @brief Új játék objektum hozzáadása.
	/// @param entity A játék objektumra mutató pointer.
	void addEntity(GameObject* entity);

private:
	/// @brief Következő pálya betöltése.
	void loadNextLevel();

	bool _isGameOver;
	std::vector<Level*> _levels;
	std::list<GameObject*> _entities;
	int _score;
	int _currentLevel;
	int _activeEnemies;
};

#endif