#pragma once 

#include "../../GameObject.h"
#include <iostream>

class Enemy : public GameObject {
public:
	Enemy(const Rectangle& collider) : GameObject() {
		this->collider = collider;
		collisionMask = ENEMY;
	}

	~Enemy() {
		std::cout << "Enemy destroyed" << std::endl;

	}

	void handleInput(float dt) override {};
	void render() override {
		if (!playerInLight) [[unlikely]] return;
		DrawRectangleRec(collider, RED);
	}
};