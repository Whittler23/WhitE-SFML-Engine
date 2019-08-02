#pragma once

#include "Logger/logger.hpp"
#include "Logger/logRecord.hpp"

#ifdef WE_DEBUG

#define WE_LOG_INFO(message)\
	WhitE::Logger::outputLog(WhitE::LogLevel::Info, message, __LINE__)
#define WE_LOG_ERROR(message)\
	WhitE::Logger::outputLog(WhitE::LogLevel::Error, message, __LINE__)
#define WE_LOG_CRITICAL(message)\
	WhitE::Logger::outputLog(WhitE::LogLevel::Error, message, __LINE__)

#else 

#define WE_LOG_INFO(message)
#define WE_LOG_ERROR(message)
#define WE_LOG_CRITICAL(message)

#endif //WE_DEBUG


#define WE_LOG(logLevel, message)\
	WhitE::Logger::outputLog(logLevel, message, __LINE__)



