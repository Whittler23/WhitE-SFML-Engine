#include "gameEngine.hpp"
#include "Logger/logInitializer.hpp"
#include "Logger/logs.hpp"
#include "Input/actionManager.hpp"

#include "States/introState.hpp"

#include <stdexcept>

#ifdef WE_WINDOWS
#include <Windows.h>
#endif

namespace {

	std::vector<std::pair<std::string, sf::Keyboard::Key>> initActionsVector = {
	{ std::make_pair("SwitchDebugger", sf::Keyboard::Tab)	},
	{ std::make_pair("PopState", sf::Keyboard::BackSpace)	},
	{ std::make_pair("PushGame", sf::Keyboard::G)			},
	{ std::make_pair("PushIntro", sf::Keyboard::I)			}
	};

}

void showMessageBox(const std::string& str)
{
	MessageBoxA(nullptr, str.c_str(), "Error", MB_OK | MB_ICONERROR);
}

int main()
{
try {
	WhitE::initializeLogger("conf/logConf.ini");
	WE_INFO("WhitE engine started!");

	WhitE::GameEngine gameEngine;

	gameEngine.initState(std::make_unique<WhitE::IntroState>(gameEngine.getSharedData()));
	gameEngine.initGlobalActions(initActionsVector);

	gameEngine.start();
}

catch (std::exception& e)
{
	showMessageBox(e.what());
	throw;
}
catch (...)
{
	showMessageBox("Unknown Error!");
	throw;
}
}