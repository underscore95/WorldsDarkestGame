#pragma once

#include "../Scene.h"
#include "Player.h"
#include <memory>

class Goal;

class GameScene : public Scene {
private:
	void handleInput(float dt) override;

	void update(float dt) override;

	void render() override;

	Player player;
	Goal* goal;

public:
	GameScene(unsigned int level = 0);
};