#pragma once

#include "Scene.h"
#include <string>

class GameOverScene : public Scene {
private:
	const std::string gameOverText;
	const std::string playAgainText = "Press R to play again";

	void handleInput(float dt) override;

	void update(float dt) override;

	void render() override;

public:
	GameOverScene(const std::string& gameOverText);
};