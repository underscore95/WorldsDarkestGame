#pragma once

#include "../GameObject.h"

class Portal : public GameObject {
private:
	const Vector2 dest;
public:
	Portal(const Rectangle& collider, const Vector2& dest);

	void handleInput(float dt) override {};
	void update(float dt) override {};
	void render() override;

	const Vector2& getDest() const {
		return dest;
	}
};