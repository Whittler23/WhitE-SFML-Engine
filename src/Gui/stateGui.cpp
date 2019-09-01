#include "Gui/stateGui.hpp"
#include "Gui/guiElement.hpp"
#include "Logger/logs.hpp"

#include <SFML/System.hpp>

namespace WhitE {

StateGui::StateGui()
{
}

void StateGui::updateGui(const sf::Time& deltaTime)
{
	for (auto& guiElement : mStateGuiElements)
	{
		guiElement->update(deltaTime);
	}
}

void StateGui::inputGui()
{
	for (auto& guiElement : mStateGuiElements)
	{
		guiElement->input();
	}
}

void StateGui::addGuiElement(std::unique_ptr<GuiElement> guiElement)
{
	WE_CORE_INFO("Gui element \"" + guiElement->getName() + "\" was added");

	mStateGuiElements.emplace_back(std::move(guiElement));
}

void StateGui::removeGuiElement(const std::string& guiElementName)
{
	for (auto it = mStateGuiElements.begin(); it != mStateGuiElements.end(); ++it)
		if ((*it)->getName() == guiElementName)
		{
			WE_CORE_INFO("Gui element \"" + guiElementName + "\" was removed");
			mStateGuiElements.erase(it);
			return;
		}

	WE_CORE_INFO("Gui element \"" + guiElementName + "\" does not exist and could not be removed");
}


}