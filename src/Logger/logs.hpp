#pragma once

#include "Logger/logger.hpp"

namespace WhitE {

#define WE_LOG(LogLevel, message)/
	Logger::outputLog(logLevel, message, __LINE__)

#define WE_LOG_ERROR(message)

#define WE_LOG_CRITICAL(message)

#define WE_LOG_INFO(message)

}
