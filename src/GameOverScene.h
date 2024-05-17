#pragma once

#include "Scene.h"
#include <string>

class GameOverScene : public Scene {
private:
	const std::string gameOverText;
	const std::string playAgainText = "Press R to play again.\n\nDeveloped by underscore95\n\nMusic:\nMoonlight by Scott Buckley | www.scottbuckley.com.au\nMusic promoted by https ://www.chosic.com/free-music/all/\nCreative Commons CC BY 4.0\nhttps ://creativecommons.org/licenses/by/4.0/";

	void handleInput(float dt) override;

	void update(float dt) override;

	void render() override;

public:
	GameOverScene(const std::string& gameOverText);
};