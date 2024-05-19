#include "Door.h"
#include "../Game.h"
#include "../Scene.h"
#include "Key.h"

constexpr float DARKNESS = 0.5f;

Door::Door(Scene* scene, const Rectangle& collider, const Vector2& key, const Color& color) : color(color), dark{ Color(color.r * DARKNESS,
	color.g * DARKNESS, color.b * DARKNESS, color.a * DARKNESS) }
{
	this->collider = collider;
	collisionMask = GameObject::WALL;

	Key* keyObj = new Key(this, key, this->color);
	scene->addGameObject(keyObj);
}

void Door::render()
{
	if (!playerInLight) [[unlikely]] return;
	if (collisionMask == GameObject::NONE) return;

	DrawRectangleRec(collider, color);
	DrawRectangle(collider.x + collider.width / 2.0 - 4, collider.y + collider.height / 2.0 - 4, 8, 8, dark);
}
