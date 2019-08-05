#pragma once

#include "Logger/logger.hpp"
#include "Logger/logRecord.hpp"

using namespace std::string_literals;

#define WE_LOG(logLevel, message)\
	WhitE::Logger::outputLog(logLevel, message)

#ifdef WE_DEBUG

#define WE_INFO(message)		WE_LOG(WhitE::LogLevel::Info, message)
#define WE_WARNING(message)		WE_LOG(WhitE::LogLevel::Warning, message)
#define WE_ERROR(message)		WE_LOG(WhitE::LogLevel::Error, message)
#define WE_CRITICAL(message)	WE_LOG(WhitE::LogLevel::Critical, message)

#define WE_CORE_INFO(message)		WE_LOG(WhitE::LogLevel::Info, "| WhitE | "s + message)
#define WE_CORE_WARNING(message)	WE_LOG(WhitE::LogLevel::Warning, "| WhitE | "s +  message)
#define WE_CORE_ERROR(message)		WE_LOG(WhitE::LogLevel::Error, "| WhitE | "s + message)
#define WE_CORE_CRITICAL(message)	WE_LOG(WhitE::LogLevel::Critical, "| WhitE | "s + message)

#else 

#define WE_LOG_INFO(message)
#define WE_LOG_WARNING(message)
#define WE_LOG_ERROR(message)
#define WE_LOG_CRITICAL(message)

#define WE_CORE_INFO(message)
#define WE_CORE_WARNING(message)	
#define WE_CORE_ERROR(message)		
#define WE_CORE_CRITICAL(message)

#endif //WE_DEBUG






