#pragma once

#include "Gui/guiElement.hpp"

#include <SFML/System.hpp>

#include <list>

namespace WhitE {

class StateGui 
{
public:
	StateGui();

	void updateGui(const sf::Time& deltaTime);
	void inputGui();

	void addGuiElement(std::unique_ptr<GuiElement> guiElement);
	void removeGuiElement(const std::string& guiElementName);

	auto getStateGuiElements() -> std::list<std::unique_ptr<GuiElement>> * { return &mStateGuiElements; }

private:
	std::list<std::unique_ptr<GuiElement>> mStateGuiElements;

};

}
