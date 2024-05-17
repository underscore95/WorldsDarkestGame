#pragma once

#include "Level.h"

class Level2 : public Level {
public:
	void load(GameScene* gameScene) override {
		gameScene->addGameObject(new Wall({ 515, 235, 100, 420 }));
		gameScene->addGameObject(new Wall({ 615, 235, 465, 100 }));
		gameScene->addGameObject(new Wall({ 980, 235, 100, 300 }));
		gameScene->addGameObject(new Wall({ 900, 100, 75, 75 }));
		gameScene->addGameObject(new Wall({ 700, 160, 75, 75 }));

		gameScene->addGameObject(new Light({ 1080, 300, 100, 100 }));

		gameScene->addGameObject(new PathEnemy<2>({ { {666, 550}, {1130, 550} } }, 300.0));
		gameScene->addGameObject(new PathEnemy<2>({ { {535, 145}, {145, 145} } }, 300.0));

	}

	Goal* getGoal() override {
		return new Goal({ 100, 520, 100, 100 });
	}
};