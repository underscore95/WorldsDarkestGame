#pragma once

#include "Level.h"

class Level0 : public Level {
public:
	void load(GameScene* gameScene) override {
		gameScene->addGameObject(new Wall({ 200, 200, 100, 100 }));

		gameScene->addGameObject(new PathEnemy<2>({ { {400, 500}, {400, 250} } }, 300.0));
	}

	Goal* getGoal() override {
		return new Goal({ 100, 100, 100, 100 });
	}
};