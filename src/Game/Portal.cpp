#include "Portal.h"

Portal::Portal(const Rectangle& collider, const Vector2& dest) : dest(dest)
{
	this->collider = collider;
	collisionMask = GameObject::PORTAL;
}

void Portal::render()
{
	DrawRectangleRec(collider, GREEN);
	DrawCircle(dest.x, dest.y, 5, DARKGREEN);
}
