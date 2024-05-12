#include <raylib.h>
#include <iostream>
#include <chrono>
#include "Game.h"
#include "Scene.h"
#include "Game/GameScene.h"
#include <iostream>

Scene* nextScene = nullptr;
Scene* scene;

int main() {

	scene = new GameScene(0);

	InitWindow(1280, 720, "Worlds Darkest Game");

	float dt = 1.0 / 60.0;

	while (!WindowShouldClose()) {
		const auto startFrame = std::chrono::high_resolution_clock::now();

		scene->frame(dt);

		if (nextScene != nullptr) {
			delete scene;
			scene = nextScene;
			nextScene = nullptr;
		}

#ifndef NDEBUG
		std::cout << GetMouseX() << " " << GetMouseY() << std::endl;
#endif

		const auto endFrame = std::chrono::high_resolution_clock::now();
		const auto duration = std::chrono::duration_cast<std::chrono::microseconds>(endFrame - startFrame);
		dt = duration.count() / 1000000.0f;
	}

	return 0;
}

void setScene(Scene* scene)
{
#ifndef NDEBUG
	if (nextScene != nullptr) {
		std::cout << "Scene changed twice in the same frame!" << std::endl;
	}
#endif

	nextScene = scene;
}

Scene& getScene()
{
	return *scene;
}
