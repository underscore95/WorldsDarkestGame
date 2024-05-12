#include "Wall.h"

Wall::Wall(const Rectangle& collider) : GameObject()
{
	this->collider = collider;
	collisionMask = WALL;
}

void Wall::render()
{
	DrawRectangleRec(collider, DARKBLUE);
}
