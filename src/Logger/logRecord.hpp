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
	LogRecord(LogLevel logLvl, std::string mes, unsigned int line, float time)
		:mLogLevel(logLvl)
		, mMessage(mes)
		, mFileLine(line)
		, mTimeFromStart(time)
	{}

	LogLevel mLogLevel;
	std::string mMessage;
	unsigned int mFileLine;
	float mTimeFromStart;
};

}
