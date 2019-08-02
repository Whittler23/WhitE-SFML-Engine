#include "Logger/LogHandlers/consoleHandler.hpp"
#include "Logger/logRecord.hpp"

#include <iostream>
#include <iomanip>

namespace WhitE {

void ConsoleHandler::utilizeLog(const LogRecord& logRecord)
{
	std::cout << "[  " << std::left << std::setw(7)
		<< std::to_string(logRecord.mTimeFromStart).erase(5, 4) << "s ]";
}

}