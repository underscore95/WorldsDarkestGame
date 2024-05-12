#include "Scene.h"

#include "GameObject.h"
#include <raylib.h>

Scene::~Scene()
{
	// fuck it memory leak
}

void Scene::addGameObject(GameObject* gameObject)
{
	gameObjects.push_back(gameObject);
}

const std::vector<GameObject*>& Scene::getGameObjects() const
{
	return gameObjects;
}

void Scene::frame(float dt)
{
	BeginDrawing();
	ClearBackground(BLACK);

	for (auto& gameObject : gameObjects) {
		gameObject->handleInput(dt);
	}
	handleInput(dt);


	for (auto& gameObject : gameObjects) {
		gameObject->update(dt);
	}
	update(dt);

	if (rendering) {
		for (auto& gameObject : gameObjects) {
			gameObject->render();
		}
		render();
	}

	for (size_t i = 0; i < gameObjects.size(); i++) {
		if (gameObjects[i]->isDead()) {
			gameObjects.erase(gameObjects.begin() + i);
			i--;
		}
	}

	EndDrawing();
}
