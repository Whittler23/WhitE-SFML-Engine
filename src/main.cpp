#include "gameEngine.hpp"
#include "Logger/logInitializer.hpp"
#include "Logger/logs.hpp"
#include "Input/actionManager.hpp"
#include "testState.hpp"

#include <stdexcept>

#ifdef WE_WINDOWS
#include <Windows.h>
#endif

namespace {

	std::vector<std::pair<std::string, sf::Keyboard::Key>> initActionsVector = {
	{ std::make_pair("changeSize", sf::Keyboard::Space)	},
	{ std::make_pair("changeSizePercent", sf::Keyboard::Enter)	},
	};

	std::vector<std::pair<std::string, std::string>> initFontsVector = {
	{ std::make_pair("testFont", "resources/fonts/testFont.ttf")	},
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

	WE_INFO("===============================================");
	WE_INFO("		WhitE engine started!				");
	WE_INFO("===============================================");

	WhitE::GameEngine gameEngine;

	gameEngine.initGameFonts(initFontsVector);
	gameEngine.initGlobalActions(initActionsVector);
	gameEngine.initState(std::make_unique<WhitE::TestState>(gameEngine.getSharedData()));

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