#include "Logger/handler.hpp"

namespace WhitE {

Handler::Handler()
{

}

void Handler::handleLog(const LogRecord& logRecord)
{
	utilizeLog(logRecord);
}

}