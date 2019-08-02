#pragma once

#include "Logger/logRecord.hpp"

#include <SFML/System/Clock.hpp>

#include <string>

namespace WhitE {

class Logger
{
public:
	static void outputLog(LogLevel logLevel, const std::string& message, unsigned int line);

	static float getTimeSinceBeginning() { return mClockSinceBeginning.getElapsedTime().asSeconds(); }

private:
	static sf::Clock mClockSinceBeginning;
};

}
