#pragma once

#include <vector>

class GameObject;

class Scene {
private:
	virtual void handleInput(float dt) = 0;
	virtual void update(float dt) = 0;
	virtual void render() = 0;

	std::vector<GameObject*> gameObjects;
public:
	virtual ~Scene();

	void addGameObject(GameObject* gameObject);
	const std::vector<GameObject*>& getGameObjects() const;

	virtual void frame(float dt) final;
};