#pragma once

#include <raylib.h>
#include <cmath>

[[nodiscard]] inline const float vectorLength(const Vector2& vector)
{
	return sqrtf(vector.x * vector.x + vector.y * vector.y);
}

[[nodiscard]] inline constexpr const float vectorLengthSquared(const Vector2& vector)
{
	return vector.x * vector.x + vector.y * vector.y;
}

inline void vectorNormalize(Vector2& vector)
{
	const float length = vectorLength(vector);
	vector.x /= length;
	vector.y /= length;
}

inline constexpr void vectorScale(Vector2& vector, const float scalar) {
	vector.x *= scalar;
	vector.y *= scalar;
}

inline constexpr const Vector2 subtract(const Vector2& a, const Vector2& b) {
	return { a.x - b.x, a.y - b.y };
}