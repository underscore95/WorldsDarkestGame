#include "GameScene.h"
#include <raylib.h>
#include "Wall.h"
#include "Goal.h"
#include "Levels/Level.h"
#include "../Game.h"
#include <string>

void GameScene::handleInput(float dt)
{
	if (IsKeyPressed(KEY_R)) {
		setScene(new GameScene(level));
		++deaths;
	}
}

void GameScene::update(float dt)
{

}

void GameScene::render()
{
	const std::string restartText = std::to_string(deaths) + " deaths.\nPress R to restart";
	DrawText(restartText.c_str(), 20, 20, 20, WHITE);
}

GameScene::GameScene(unsigned int level) : level(level), player(level)
{
	auto gameLevel = Level::getLevel(level);
	player.teleport(gameLevel->getPlayerSpawn());

	// Spawn light at player spawn
	addGameObject(new Light({ player.getCollider().x - (player.getCollider().width / 2), player.getCollider().y - (player.getCollider().height / 2), 100, 100 }));

	// Walls to prevent player exiting window
	addGameObject(new Wall({ 0, 0, 1180, 100 }));
	addGameObject(new Wall({ 0, 620, 1180, 100 }));
	addGameObject(new Wall({ 0, 0, 100, 1180 }));
	addGameObject(new Wall({ 1180, 0, 100, 1180 }));

	// Load level
	gameLevel->load(this);
	goal = gameLevel->getGoal();
	addGameObject(goal);

	// Player
	addGameObject(&player);

	GameObject::playerInLight = true;
}
