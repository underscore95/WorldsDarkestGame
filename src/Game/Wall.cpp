#include "Wall.h"

Wall::Wall(const Rectangle& collider) : GameObject()
{
	this->collider = collider;
	collisionMask = WALL;
}

void Wall::render()
{
	if (!playerInLight) [[unlikely]] return;
	DrawRectangleRec(collider, DARKBLUE);
}
