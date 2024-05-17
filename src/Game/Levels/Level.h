#pragma once

#include "../GameScene.h"
#include "../Wall.h"
#include "../Light.h"
#include "../enemies/PathEnemy.h"
#include <memory>
#include <raylib.h>
#include "../Goal.h"
#include "../Portal.h"

class Level {
public:
	virtual void load(GameScene* gameScene) = 0;
	virtual Goal* getGoal() = 0;

	[[nodiscard]] static std::unique_ptr<Level> getLevel(unsigned int level);
};