#include "Gui/baseGuiSet.hpp"
#include "Gui/guiElement.hpp"
#include "Logger/logs.hpp"

#include <SFML/System.hpp>

namespace WhitE {

BaseGuiSet::BaseGuiSet(const std::string& guiSetName)
	:mName(guiSetName)
{
}

void BaseGuiSet::updateGuiElements(const sf::Time& deltaTime)
{
	for (auto& guiElement : mGuiSetElements)
		guiElement->update(deltaTime);
}

void BaseGuiSet::inputGuiElements()
{
	for (auto& guiElement : mGuiSetElements)
		guiElement->input();
}

void BaseGuiSet::addGuiElement(std::unique_ptr<GuiElement> guiElement)
{
	WE_CORE_INFO("Gui element \"" + guiElement->getName() + "\" was added");

	mGuiSetElements.emplace_back(std::move(guiElement));
}

void BaseGuiSet::removeGuiElement(const std::string& guiElementName)
{
	for (auto it = mGuiSetElements.begin(); it != mGuiSetElements.end(); ++it)
		if ((*it)->getName() == guiElementName)
		{
			WE_CORE_INFO("Gui element \"" + guiElementName + "\" was removed");
			mGuiSetElements.erase(it);
			return;
		}

	WE_CORE_INFO("Gui element \"" + guiElementName + "\" does not exist and could not be removed");
}

std::string BaseGuiSet::getName() const
{
	return mName;
}

auto BaseGuiSet::getGuiSetElements() const -> const std::list<std::unique_ptr<GuiElement>>*
{
	return &mGuiSetElements;
}


}