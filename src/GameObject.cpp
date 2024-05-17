#include "GameObject.h"

#include "Game.h"
#include "Scene.h"

bool GameObject::playerInLight = true;

const OptionalCollider GameObject::isColliding(const uint64_t collisionMask) const
{
	for (auto gameObject : getScene().getGameObjects()) {
		if (gameObject == this) [[unlikely]] continue;
		if ((gameObject->collisionMask & collisionMask) == 0) continue;

		if (CheckCollisionRecs(collider, gameObject->getCollider())) {
			return OptionalCollider(gameObject);
		}
	}
	return OptionalCollider(nullptr);
}
