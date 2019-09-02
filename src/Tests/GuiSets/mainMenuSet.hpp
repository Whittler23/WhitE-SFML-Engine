#pragma once

#include "Gui/baseGuiSet.hpp"
#include "Gui/GuiElements/button.hpp"

namespace WhitE {

class MainMenuButtonsSet : public BaseGuiSet
{
public:
	MainMenuButtonsSet(SharedData& sharedData)
		:BaseGuiSet("Main Menu Buttons")
	{
		addGuiElement(std::make_unique<Button>(sharedData, sf::Vector2f(30, 15), sf::Vector2f(40, 15), "PLAY"));
		addGuiElement(std::make_unique<Button>(sharedData, sf::Vector2f(30, 35), sf::Vector2f(40, 15), "SETTINGS"));
		addGuiElement(std::make_unique<Button>(sharedData, sf::Vector2f(30, 55), sf::Vector2f(40, 15), "CREDITS"));
		addGuiElement(std::make_unique<Button>(sharedData, sf::Vector2f(30, 75), sf::Vector2f(40, 15), "EXIT"));
	}
};

}