#pragma once

#include "Logger/handler.hpp"

namespace WhitE {

class ConsoleHandler : public Handler
{
private:
	void utilizeLog(const LogRecord&) override;

};

}