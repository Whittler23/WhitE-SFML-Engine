#pragma once

#include "Gui/guiElement.hpp"

#include <SFML/System.hpp>

#include <list>

namespace WhitE {

class BaseGuiSet
{
public:
	BaseGuiSet(const std::string& guiSetName);

	void updateGuiElements(const sf::Time& deltaTime);
	void inputGuiElements();

	void addGuiElement(std::unique_ptr<GuiElement> guiElement);
	void removeGuiElement(const std::string& guiElementName);

	std::string getName() const;
	auto getGuiSetElements() const -> const std::list<std::unique_ptr<GuiElement>>*;

private:
	std::list<std::unique_ptr<GuiElement>> mGuiSetElements;
	std::string mName;

};

}
