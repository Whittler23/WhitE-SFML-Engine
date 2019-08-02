#include "Logger/handler.hpp"

namespace WhitE {

Handler::Handler()
{

}

std::ostream& operator<<(std::ostream& os, const LogLevel& dt)
{
	switch (dt)
	{
	case LogLevel::Info:
		os << "Info";
		return os;
	case LogLevel::Error:
		os << "Error";
		return os;
	case LogLevel::Warning:
		os << "Warning";
		return os;
	case LogLevel::Critical:
		os << "Critical";
		return os;
	}
}

void Handler::handleLog(const LogRecord& logRecord)
{
	utilizeLog(logRecord);
}

}