#pragma once

#include "Level.h"

class Level4 : public Level {
public:
	void load(GameScene* gameScene) override {

		gameScene->addGameObject(new Wall({ 770, 100, 115, 285 }));
		gameScene->addGameObject(new Wall({ 830, 270, 350, 115 }));

		gameScene->addGameObject(new Portal({ 900, 480, 55, 55 }, { 1125, 160 }, GREEN));
		gameScene->addGameObject(new Portal({ 885, 225, 45, 45 }, { 150,150 }, ORANGE));


		for (float y = 0; y < 460; y += 70) {
			gameScene->addGameObject(new PathEnemy<2>({ { {360, 125 + y}, {530, 125 + y} } }, 100.0));
		}

		gameScene->addGameObject(new PathEnemy<5>({ { {810, 425}, {810, 550}, {1030, 550}, {1030, 425}, {810, 425} } }, 300.0));

	}

	Goal* getGoal() override {
		return new Goal({ 100, 520, 100, 100 });
	}
};