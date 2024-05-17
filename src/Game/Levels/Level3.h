#pragma once

#include "Level.h"

class Level3 : public Level {
public:
	void load(GameScene* gameScene) override {
		gameScene->addGameObject(new Wall({ 470, 260, 375, 75 }));
		gameScene->addGameObject(new Wall({ 920, 260, 185, 75 }));
		gameScene->addGameObject(new Wall({ 545, 335, 75, 210 })); 
		gameScene->addGameObject(new Wall({ 1030, 185, 150, 75 }));
		gameScene->addGameObject(new Wall({ 620, 470, 75, 75 }));
		gameScene->addGameObject(new Wall({ 770, 335, 75, 135 }));
		gameScene->addGameObject(new Wall({ 770, 545, 75, 75 }));
		gameScene->addGameObject(new Wall({ 920, 410, 75, 250 }));
		gameScene->addGameObject(new Wall({ 995, 410, 110, 75 }));
		gameScene->addGameObject(new Wall({ 995, 485, 110, 60 }));
		gameScene->addGameObject(new Wall({ 470, 185, 375, 75 }));
		gameScene->addGameObject(new Wall({ 395, 260, 75, 360 }));
		gameScene->addGameObject(new Wall({ 100, 100, 220, 420 }));
		gameScene->addGameObject(new Light({ 470, 335, 75, 75 }));
		gameScene->addGameObject(new PathEnemy<2>({ { {350, 135}, {350, 135} } }, 300.0));


	}

	Goal* getGoal() override {
		return new Goal({ 100, 520, 100, 100 });
	}
};