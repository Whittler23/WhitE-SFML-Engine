#include "gameEngine.hpp"

namespace WhitE {

GameEngine::GameEngine()
	:mGameWindow(sf::VideoMode::getDesktopMode(), "Test of WhitE!", sf::Style::Titlebar)
{
	start();
}

void GameEngine::start()
{
	while (mGameWindow.isOpen())	
	{

	}
}

}