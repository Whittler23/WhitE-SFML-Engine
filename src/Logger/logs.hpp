#pragma once

#include "Logger/logger.hpp"


#define WE_LOG(logLevel, message)\
	WhitE::Logger::outputLog(logLevel, message, __LINE__)

#define WE_LOG_INFO(message)\
	WhitE::Logger::outputLog(WhitE::LogLevel::Info, message, __LINE__)

#define WE_LOG_ERROR(message)\
	WhitE::Logger::outputLog(WhitE::LogLevel::Error, message, __LINE__)

#define WE_LOG_CRITICAL(message)\
	WhitE::Logger::outputLog(WhitE::LogLevel::Error, message, __LINE__)

