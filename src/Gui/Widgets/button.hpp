#pragma once

#include "Gui/Widgets/clickableWidget.hpp"

namespace WhitE::gui {

class Button : public ClickableWidget
{
public:
	Button();

	void draw(sf::RenderTarget& renderTarget, sf::RenderStates renderStates) const;


};

}

