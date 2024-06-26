#include <raylib.h>
#include <iostream>
#include <chrono>
#include "Game.h"
#include "Scene.h"
#include "Game/GameScene.h"
#include <iostream>

Scene* nextScene = nullptr;
Scene* scene;
Music music;

int main() {
	InitWindow(1280, 720, "Worlds Darkest Game");

	InitAudioDevice();
#ifdef NDEBUG
	music = LoadMusicStream("assets/music.mp3");
	music.looping = true;
	PlayMusicStream(music);
#endif

#ifdef NDEBUG
	HideCursor();
#endif

#ifdef NDEBUG
	constexpr int level = 0;
#else
	constexpr int level = 0;
#endif

	scene = new GameScene(level);

	float dt = 1.0 / 60.0;

	while (!WindowShouldClose()) {
		const auto startFrame = std::chrono::high_resolution_clock::now();

		UpdateMusicStream(music);
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

	CloseAudioDevice();

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
