#include "Key.h"
#include "Door.h"

Key::Key(Door* door, const Vector2& location, const Color& dark) : location(location), dark(dark), door(door)
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
	DrawRectangle(location.x - 5, location.y - 5, 10, 10, WHITE);
	DrawRectangle(location.x - 4, location.y - 4, 8, 8, dark);
}
