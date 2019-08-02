#pragma once

namespace WhitE {

struct LogRecord;

class Handler
{
public:
	Handler();

	void handleLog(const LogRecord&);

private:
	virtual void utilizeLog(const LogRecord&) = 0;
};

}