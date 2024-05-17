#include "Portal.h"

constexpr float DARKNESS = 0.5f;

Portal::Portal(const Rectangle& collider, const Vector2& dest, const Color& color) : dest(dest), color(color), dark{ Color(color.r * DARKNESS,
	color.g * DARKNESS, color.b * DARKNESS, color.a * DARKNESS) }
{
	this->collider = collider;
	collisionMask = GameObject::PORTAL;
}

void Portal::render()
{
	if (!playerInLight) [[unlikely]] return;
	DrawRectangleRec(collider, color);
	DrawCircle(collider.x + collider.width / 2.0, collider.y + collider.height / 2.0, 5, dark);
	DrawCircle(dest.x, dest.y, 7, WHITE);
	DrawCircle(dest.x, dest.y, 5, dark);
}
