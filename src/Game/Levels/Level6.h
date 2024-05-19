#pragma once

#include "Level.h"

class Level6 : public Level {
public:
	void load(GameScene* gameScene) override {
		gameScene->addGameObject(new Wall({ 220, 320, 100, 300 }));
		gameScene->addGameObject(new Wall({ 320, 200, 100, 220 }));
		gameScene->addGameObject(new Wall({ 550, 100, 220, 50 }));
		gameScene->addGameObject(new Wall({ 550, 250, 175, 150 }));
		gameScene->addGameObject(new Wall({ 500, 400, 150, 220 }));
		gameScene->addGameObject(new Wall({ 800, 335, 270, 165 }));
		gameScene->addGameObject(new Wall({ 725, 335, 75, 65 }));
		gameScene->addGameObject(new Wall({ 715, 455, 85, 45 }));

		gameScene->addGameObject(new Light({ 850, 150, 115, 115 }));
		gameScene->addGameObject(new Light({ 750, 575, 70, 45 }));

		gameScene->addGameObject(new PathEnemy<1>({ { {100, 450} } }, 300.0));
		gameScene->addGameObject(new Enemy({ 850, 500, 50, 30 }));
		gameScene->addGameObject(new Enemy({ 1000, 590, 50, 30 }));
		gameScene->addGameObject(new Enemy({ 1070, 450, 30, 50 }));
		gameScene->addGameObject(new Enemy({ 1150, 300, 30, 50 }));


		gameScene->addGameObject(new Door(gameScene, { 580, 150, 50, 100 }, { 160, 575 }, SKYBLUE)); 
		gameScene->addGameObject(new Door(gameScene, { 650, 455, 65, 45 }, { 1160, 120 }, PURPLE));


	}

	Goal* getGoal() override {
		return new Goal({ 715, 400, 85, 55 });
	}

	Vector2 getPlayerSpawn() override {
		return { 375, 515 };
	}
};