#pragma once

#include <string>

namespace WhitE {

enum class LogLevel
{
	Info,
	Warning,
	Error,
	Critical
};

struct LogRecord
{
	LogRecord(LogLevel logLvl, std::string mes, float time)
		:mLogLevel(logLvl)
		, mMessage(mes)
		, mTimeFromStart(time)
	{}

	LogLevel mLogLevel;
	std::string mMessage;
	float mTimeFromStart;
};

}
