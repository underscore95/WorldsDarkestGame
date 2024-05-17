#pragma once

#include "Level.h"

class Level0 : public Level {
public:
	void load(GameScene* gameScene) override {
		gameScene->addGameObject(new Wall({ 200, 300, 300, 350 })); 
		gameScene->addGameObject(new Wall({ 500, 300, 350, 35 }));
		gameScene->addGameObject(new Wall({ 200, 200, 650, 100 }));
		gameScene->addGameObject(new Wall({ 100, 200, 515, 420 }));

		gameScene->addGameObject(new Light({ 1080, 100, 100, 100 }));
	}

	Goal* getGoal() override {
		return new Goal({ 100, 100, 100, 100 });
	}
};