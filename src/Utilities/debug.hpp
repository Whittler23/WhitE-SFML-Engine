#pragma once

#include "Logger/logger.hpp"
#include "Logger/logRecord.hpp"

#include <stdexcept>

#ifdef WE_DIST

#define WE_EXCEPTION(message) throw std::runtime_error(message)

#else 

#define WE_EXCEPTION(message) { WhitE::Logger::outputLog(LogLevel::Error, message); throw std::runtime_error(message); }
	

#endif //WE_DEBUG