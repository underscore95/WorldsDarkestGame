#pragma once

#include "../GameObject.h"

class Wall : public GameObject {
public:
	Wall(const Rectangle& collider);

	void handleInput(float dt) override {};
	void update(float dt) override {};
	void render() override;
};