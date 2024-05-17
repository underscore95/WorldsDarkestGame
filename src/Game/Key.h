#pragma once

#include "../GameObject.h"

class Door;

class Key : public GameObject {
private:
	Door* door;
	const Vector2 location;
	const Color& color;
	const Color& dark;

public:
	Key(Door* door, const Vector2& location, const Color& color, const Color& dark);

	void handleInput(float dt) override {};
	void update(float dt) override;
	void render() override;
};