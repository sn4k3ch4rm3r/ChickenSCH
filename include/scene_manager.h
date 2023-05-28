#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H

#include <chrono>
#include "leaderboard.h"
#include "presentation.h"
#include "scene.h"
#include "vector2.h"

/// @brief Az egész játékot irányító osztály.
/// @details Singleton osztály, a különböző képernyők közötti váltásokat és azok frissítését, rajzolását, valamint az eseménykezelést végzi.
class SceneManager {
public:
	/// @brief A SceneManager singleton példányának lekérdezése.
	/// @return Referencia a SceneManager singleton példányára.
	static SceneManager& getInstance();

	/// @brief Másolást letiltó konstruktor.
	SceneManager(const SceneManager&) = delete;

	/// @brief Másolást letiltó értékadás operátor.
	SceneManager& operator=(const SceneManager&) = delete;
	~SceneManager();

	/// @brief Az éppen aktív képernyő frissítése.
	void update();

	/// @brief Az éppen aktív képernyő kirajzolása.
	void render();

	/// @brief Az események kezelése.
	void handleEvents();

	/// @brief Az utolsó frissítés óta eltelt idő lekérdezése.
	/// @return Az eltelt idő másodpercben.
	double getDeltaTime() const;

	/// @brief A megjelenítő lekérdezése.
	/// @return A megjelenítő.
	IPresentation* getPresentation() const { return _presentation; }

	/// @brief Futás elleőrzése.
	/// @return Igaz, ha fut, egyébként hamis.
	bool isRunning() const { return _presentation->isRunning(); }

	/// @brief A képernyő méretének lekérdezése.
	/// @return A képernyő mérete.
	Size getSize() const { return _size; }

	/// @brief Az éppen aktív képernyő lekérdezése.
	/// @return Az éppen aktív képernyő.
	Scene* getCurrentScene() const { return _currentScene; }

	/// @brief Aktív képernyő beállítása.
	/// @param scene Az aktív képernyő.
	void setCurrentScene(Scene* scene);

	/// @brief A ranglista lekérdezése.
	/// @return A ranglista.
	LeaderBoard& getLeaderBoard() { return _leaderBoard; }

private:
	/// @brief Privát konstruktor, hogy ne lehesse példányosítani.
	SceneManager();
	static SceneManager _instance;

	Size _size;
	Scene* _currentScene;
	std::chrono::nanoseconds _deltaTime;
	std::chrono::time_point<std::chrono::high_resolution_clock> _lastTime;

	IPresentation* _presentation;
	LeaderBoard _leaderBoard;
};

#endif