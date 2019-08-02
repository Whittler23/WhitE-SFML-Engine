#include <fstream>

#include "Logger/logInitializer.hpp"
#include "Utilities/debug.hpp"

namespace WhitE {

void initializeLogger(const std::string& filepath)
{
	std::fstream configFile(filepath);
	if (!configFile)
		WE_EXCEPTION("Cannot open file! Filepath:" + filepath);

	Logger::init();
}

}