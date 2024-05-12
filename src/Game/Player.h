#pragma once

#include "../GameObject.h"

class Player : public GameObject {
private:
	float speed = 300.0;
	bool isMoving = false;
	unsigned int level;
	float secsAlive = 0;
public:
	Player(unsigned int level);

	void handleInput(float dt) override;
	void update(float dt) override;
	void render() override;
};