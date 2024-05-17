#pragma once

#include "../GameObject.h"

class Scene;

class Door : public GameObject {
private:
	const Color color;
	const Color dark;
public:
	Door(Scene* scene, const Rectangle& collider, const Vector2& key, const Color& color);

	void handleInput(float dt) override {};
	void update(float dt) override {};
	void render() override;

	void unlock() {
		alive = false;
	}
};