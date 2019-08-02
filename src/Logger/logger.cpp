#include "Logger/logger.hpp"
#include "Logger/logRecord.hpp"
#include "Logger/LogHandlers/consoleHandler.hpp"
#include "Logger/handler.hpp"

namespace WhitE {

void Logger::loggerInitialize()
{
	addLogsHandler(std::make_unique<ConsoleHandler>());
}

void Logger::outputLog(LogLevel logLevel, const std::string& message, unsigned int line)
{
	LogRecord logRecord(logLevel, message, line, Logger::getTimeSinceBeginning());
	
	auto& handlers = getInstance().mHandlers;

	for (auto& handler : handlers)
	{
		handler->handleLog(logRecord);
	}
}

Logger& Logger::getInstance()
{
	static Logger gameLogger;
	return gameLogger;
}

float Logger::getTimeSinceBeginning()
{
	return getInstance().mClockSinceBeginning.getElapsedTime().asSeconds();
}

void Logger::addLogsHandler(std::unique_ptr<Handler> handler)
{
	getInstance().mHandlers.emplace_back(std::move(handler));
}

}