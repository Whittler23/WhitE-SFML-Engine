#pragma once

#include "Logger/logger.hpp"
#include "Logger/logRecord.hpp"

#define WE_LOG(logLevel, message)\
	WhitE::Logger::outputLog(logLevel, message, __LINE__)

#ifdef WE_DEBUG

#define WE_LOG_INFO(message)\
	WE_LOG(WhitE::LogLevel::Info, message)
#define WE_LOG_WARNING(message)\
	WE_LOG(WhitE::LogLevel::Warning, message)
#define WE_LOG_ERROR(message)\
	WE_LOG(WhitE::LogLevel::Error, message)
#define WE_LOG_CRITICAL(message)\
	WE_LOG(WhitE::LogLevel::Critical, message)

#else 

#define WE_LOG_INFO(message)
#define WE_LOG_WARNING(message)
#define WE_LOG_ERROR(message)
#define WE_LOG_CRITICAL(message)

#endif //WE_DEBUG




