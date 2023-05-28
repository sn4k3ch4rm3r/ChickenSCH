#ifndef SCENE_H
#define SCENE_H

/// @brief Képernyők interfésze.
class Scene {
public:
	virtual ~Scene(){};

	/// @brief A képernyő frissítése.
	virtual void update() = 0;

	/// @brief A képernyő kirajzolása.
	virtual void render() = 0;
};

#endif