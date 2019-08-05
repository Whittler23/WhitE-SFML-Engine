#include "Input/actionManager.hpp"

namespace WhitE {

ActionManager& ActionManager::getInstance()
{
	static ActionManager actionManager;
	return actionManager;
}

}