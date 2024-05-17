#include "Player.h"
#include "../Game.h"
#include "GameScene.h"
#include <cassert>
#include <iostream>
#include "../GameOverScene.h"
#include "Portal.h"

void Player::handleInput(float dt)
{
	Vector2 dp = { 0, 0 };
	if (IsKeyDown(KEY_W)) dp.y -= 1;
	if (IsKeyDown(KEY_S)) dp.y += 1;
	if (IsKeyDown(KEY_A)) dp.x -= 1;
	if (IsKeyDown(KEY_D)) dp.x += 1;

	if (dp.x != 0 || dp.y != 0) {
		vectorNormalize(dp);
		vectorScale(dp, speed * dt);

		Vector2 prevPosition = { collider.x, collider.y };

		collider.x += dp.x;
		collider.y += dp.y;

		if (isColliding(WALL)) {
			collider.x = prevPosition.x;
			collider.y = prevPosition.y;
		}
		else {
			isMoving = true;
		}
	}
}

Player::Player(unsigned int level) : level{ level }
{
	collider.x = 1280 / 2;
	collider.y = 720 / 2;
	collider.width = 50;
	collider.height = 50;
}

void Player::update(float dt)
{
	if (isMoving) {
		isMoving = false;

		playerInLight = isColliding(LIGHT_AREA);
	}

	OptionalCollider portalCollision = isColliding(PORTAL);
	if (portalCollision) [[unlikely]] {
		Portal* portal = dynamic_cast<Portal*>(portalCollision.object);
		assert(portal != nullptr);
		collider.x = portal->getDest().x - 32;
		collider.y = portal->getDest().y - 32;
		return;
	}

	if (isColliding(ENEMY)) [[unlikely]] {
		setScene(new GameScene(level));
		return;
		}

		bool reachedGoal = isColliding(GOAL);
#ifndef NDEBUG
		reachedGoal = reachedGoal || IsKeyPressed(KEY_G);
#endif
		if (reachedGoal) [[unlikely]] {
			if (level >= 100)
				setScene(new GameOverScene("You have completed all the levels!"));
			else
				setScene(new GameScene(level + 1));
			}
}

void Player::render()
{
	DrawRectangleRec(collider, WHITE);
}
