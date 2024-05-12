#pragma once

#include "GameOverScene.h"
#include <raylib.h>
#include "Game.h"
#include "Game/GameScene.h"

void GameOverScene::handleInput(float dt)
{
	if (IsKeyPressed(KEY_R))
	{
		setScene(new GameScene(0));
	}
}

void GameOverScene::update(float dt)
{
}

void GameOverScene::render()
{
	DrawText(gameOverText.c_str(), 10, 10, 20, RED);
	DrawText(playAgainText.c_str(), 10, 80, 20, RED);
}

GameOverScene::GameOverScene(const std::string& gameOverText) : gameOverText{ gameOverText }
{

}
