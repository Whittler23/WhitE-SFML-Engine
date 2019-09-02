#pragma once

#include "Gui/baseGuiSet.hpp"

namespace WhitE {

class StateGuiManager
{
public:
	StateGuiManager();

	void updateGuiSets(const sf::Time& deltaTime);
	void inputGuiSets();

	void addGuiSet(BaseGuiSet* baseGuiSet);
	void removeGuiSet(BaseGuiSet* baseGuiSet);
	void removeGuiSet(const std::string& guiSetName);

	auto getGuiSets() -> std::list<BaseGuiSet*>*;

private:
	std::list<BaseGuiSet*> mGuiSets;

};

}