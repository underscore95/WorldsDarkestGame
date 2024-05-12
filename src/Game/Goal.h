#pragma once 

#include "../GameObject.h"

class Goal : public GameObject {
public:
	Goal(const Rectangle& collider) : GameObject() {
		this->collider = collider;
		collisionMask = GOAL;
	}

	void handleInput(float dt) override {};
	void update(float dt) override {};
	void render() override {
		DrawRectangleRec(collider, PINK);
	}
};