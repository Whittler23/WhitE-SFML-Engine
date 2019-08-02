#pragma once

#include "Logger/logRecord.hpp"
#include "handler.hpp"

#include <SFML/System/Clock.hpp>

#include <string>
#include <vector>
#include <memory>

namespace WhitE {

class Logger
{
private:
	Logger() = default;
	Logger(const Logger&) = delete;
	Logger& operator=(const Logger&) = delete;

public:
	static void outputLog(LogLevel logLevel, const std::string& message, unsigned int line);

	static void init();
	static void addLogsHandler(std::unique_ptr<Handler> handler);
	static void removeLogsHandler(std::unique_ptr<Handler> handler);

	static float getTimeSinceBeginning();

private:
	static Logger& getInstance();

private:
	sf::Clock mClockSinceBeginning;
	std::vector < std::unique_ptr<Handler> > mHandlers;
};

}
