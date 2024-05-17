#include "Key.h"
#include "Door.h"

Key::Key(Door* door, const Vector2& location, const Color& color, const Color& dark) : location(location), color(color), dark(dark), door(door)
{
	collider = { location.x, location.y, 10, 10 };
	collisionMask = GameObject::NONE;
}

void Key::update(float dt)
{
	if (isColliding(PLAYER)) [[unlikely]] {
		alive = false;
		door->unlock();
	}
}

void Key::render()
{
	if (!playerInLight) [[unlikely]] return;
	DrawRectangle(location.x - 3.5, location.y - 3.5, 7, 7, WHITE);
	DrawRectangle(location.x - 2.5, location.y - 2.5, 5, 5, dark);
}
