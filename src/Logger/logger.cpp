#include "Logger/logger.hpp"
#include "Logger/logRecord.hpp"

namespace WhitE {


void Logger::outputLog(LogLevel logLevel, const std::string& message, unsigned int line)
{
	LogRecord logRecord(logLevel, message, line, Logger::getTimeSinceBeginning());


}
}