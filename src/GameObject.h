#pragma once

#include <raylib.h>
#include "Utils/Math.h"

class GameObject;

struct OptionalCollider {
	GameObject* object;

	OptionalCollider(GameObject* object) : object(object) {}
	
	[[nodiscard]] operator bool() const {
		return object != nullptr;
	}
};

class GameObject {
protected:
	bool alive = true; // If false, the object will be removed from the game after the current frame updates
	Rectangle collider{ 0,0, 0, 0 };

public:
	static constexpr uint64_t WALL = 1 << 0;
	static constexpr uint64_t LIGHT_AREA = 1 << 1;
	static constexpr uint64_t ENEMY = 1 << 2;
	static constexpr uint64_t GOAL = 1 << 3;
	static constexpr uint64_t PORTAL = 1 << 4;

	uint64_t collisionMask = 0;

	virtual void handleInput(float dt) = 0;
	virtual void update(float dt) = 0;
	virtual void render() = 0;

	[[nodiscard]] const bool isDead() const {
		return !alive;
	}

	[[nodiscard]] const Rectangle& getCollider() const {
		return collider;
	}

	[[nodiscard]] const OptionalCollider isColliding(const uint64_t collisionMask) const;

	static bool playerInLight;
};