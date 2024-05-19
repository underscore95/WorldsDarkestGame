#pragma once

#include "Level.h"

class Level5 : public Level {
public:
	void load(GameScene* gameScene) override {
		gameScene->addGameObject(new Wall({ 100, 420, 250, 100 }));
		gameScene->addGameObject(new Door(gameScene, { 250, 520, 100, 100 }, { 150, 150 }, ORANGE));

		gameScene->addGameObject(new PathEnemy<5>({ { {150, 220}, {200, 220}, {200, 150}, {200, 220}, {150, 220} } }, 100.0));


	}

	Goal* getGoal() override {
		return new Goal({ 100, 520, 100, 100 });
	}
};