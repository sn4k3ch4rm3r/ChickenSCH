#ifndef SCENE_H
#define SCENE_H

class Scene {
public:
	virtual ~Scene(){};

	virtual void update() = 0;
	virtual void render() = 0;
	Scene* nextScene() const { return _nextScene; }

protected:
	Scene* _nextScene;
};

#endif