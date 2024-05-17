#include "GameScene.h"
#include <raylib.h>
#include "Wall.h"
#include "Goal.h"
#include "Levels/Level.h"

void GameScene::handleInput(float dt)
{
}

void GameScene::update(float dt)
{

}

void GameScene::render()
{
}

GameScene::GameScene(unsigned int level) : player(level)
{
	// Spawn light at player spawn
	addGameObject(new Light({ player.getCollider().x - (player.getCollider().width / 2), player.getCollider().y - (player.getCollider().height / 2), 100, 100 }));

	// Walls to prevent player exiting window
	addGameObject(new Wall({ 0, 0, 1180, 100 }));
	addGameObject(new Wall({ 0, 620, 1180, 100 }));
	addGameObject(new Wall({ 0, 0, 100, 1180 }));
	addGameObject(new Wall({ 1180, 0, 100, 1180 }));

	// Load level
	auto gameLevel = Level::getLevel(level);
	gameLevel->load(this);
	goal = gameLevel->getGoal();
	addGameObject(goal);

	// Player
	addGameObject(&player);

	GameObject::playerInLight = true;
}
