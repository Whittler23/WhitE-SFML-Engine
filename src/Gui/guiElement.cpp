#include "Gui/guiElement.hpp"

namespace WhitE {

GuiElement::GuiElement(SharedData& sharedData, const std::string& name)
	:mSharedData(sharedData)
	,mGuiElementName(name)
	,mVisible(true)
{
}

void GuiElement::update(const sf::Time& deltaTime) 
{
}

void GuiElement::input() 
{
}

auto GuiElement::getName() const -> const std::string &
{
	return mGuiElementName;
}



}