#include "Gui/stateGuiManager.hpp"
#include "Logger/logs.hpp"

namespace WhitE {

StateGuiManager::StateGuiManager()
{
}

void StateGuiManager::updateGuiSets(const sf::Time& deltaTime)
{
	for (auto& guiSet : mGuiSets)
		guiSet->updateGuiElements(deltaTime);
}

void StateGuiManager::inputGuiSets()
{
	for (auto& guiSet : mGuiSets)
		guiSet->inputGuiElements();
}

void StateGuiManager::addGuiSet(BaseGuiSet* baseGuiSet)
{
	mGuiSets.emplace_back(baseGuiSet);

	WE_CORE_INFO("\"" + baseGuiSet->getName() + "\" GUI set was added to the State Gui Manager");
}

void StateGuiManager::removeGuiSet(BaseGuiSet* baseGuiSet)
{
	for (auto it = mGuiSets.begin(); it != mGuiSets.end(); ++it)
		if (*it == baseGuiSet)
		{
			WE_CORE_INFO("\"" + baseGuiSet->getName() + "\" GUI set was erased from the State Gui Manager");
			mGuiSets.erase(it);
			return;
		}
}

void StateGuiManager::removeGuiSet(const std::string& guiSetName)
{
	for (auto it = mGuiSets.begin(); it != mGuiSets.end(); ++it)
		if ((*it)->getName() == guiSetName)
		{
			WE_CORE_INFO("\"" + guiSetName + "\" GUI set was erased from the State Gui Manager");
			mGuiSets.erase(it);
			return;
		}

	WE_CORE_WARNING("\"" + guiSetName + "\" GUI set does not exist and couldn't be erased from the State Gui Manager");
}

auto StateGuiManager::getGuiSets() -> std::list<BaseGuiSet*>*
{
	return &mGuiSets;
}

}