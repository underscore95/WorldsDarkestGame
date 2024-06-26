#pragma once

#include "../GameObject.h"

class Player : public GameObject {
private:
	float speed = 300.0;
	bool isMoving = false;
	unsigned int level;
public:
	Player(unsigned int level);

	void handleInput(float dt) override;
	void update(float dt) override;
	void render() override;

	void teleport(const Vector2& position);
};