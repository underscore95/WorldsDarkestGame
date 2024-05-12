#pragma once

#include "Enemy.h"
#include <array>

template <size_t Size>
class PathEnemy : public Enemy {
private:
	std::array<Vector2, Size> path;
	size_t currentPathIndex = 0;
	float speed;
public:
	PathEnemy(const std::array<Vector2, Size>& path, float speed) : Enemy({ path[0].x, path[0].y, 50, 50 }), path(path), speed(speed) {}

	void update(float dt) override {
		const auto currentPath = path[currentPathIndex];
		const auto nextPath = path[(currentPathIndex + 1) % Size];

		auto direction = subtract(nextPath, currentPath);
		vectorNormalize(direction);
		const auto dp = speed * dt;
		vectorScale(direction, dp);

		if (vectorLengthSquared(subtract(Vector2{ collider.x, collider.y }, nextPath)) < dp * dp) [[unlikely]] {
			collider.x = nextPath.x;
			collider.y = nextPath.y;
			currentPathIndex = (currentPathIndex + 1) % Size;
		}
		else {
			collider.x += direction.x;
			collider.y += direction.y;
		}
	}

	void render() override {
		DrawRectangleRec(collider, RED);
	}
};