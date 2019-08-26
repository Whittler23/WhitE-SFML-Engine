#include "gameEngine.hpp"
#include "Logger/logInitializer.hpp"
#include "Logger/logs.hpp"

#include "States/introState.hpp"

#include <stdexcept>

#ifdef WE_WINDOWS
#include <Windows.h>
#endif

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

	gameEngine.setInitState(std::make_unique<WhitE::IntroState>(gameEngine.getSharedData()));

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