#pragma once

#include <iostream>
#include "logRecord.hpp"

namespace WhitE {

class Handler
{
public:
	Handler();

	void handleLog(const LogRecord&);

private:
	friend std::ostream& operator<<(std::ostream& os, const LogLevel& dt);
	virtual void utilizeLog(const LogRecord&) = 0;
};

}