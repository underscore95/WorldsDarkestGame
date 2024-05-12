#pragma once 

#include "../GameObject.h"

class Light : public GameObject {
public:
	Light(const Rectangle& collider) : GameObject() {
		this->collider = collider;
		collisionMask = LIGHT_AREA;

	}

	void handleInput(float dt) override {};
	void update(float dt) override {};
	void render() override {
		DrawRectangleRec(collider, YELLOW);
	}
};