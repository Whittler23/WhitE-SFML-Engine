#include "button.hpp"
#include "Gui/Widgets/button.hpp"

namespace WhitE::gui{

Button::Button()
{
}

void Button::draw(sf::RenderTarget& renderTarget, sf::RenderStates renderStates) const
{
	if (!hasTexture())
	{
		sf::RectangleShape buttonBody;
		buttonBody.setPosition(getPosition());
		buttonBody.setSize(getSize());
		renderTarget.draw(buttonBody, renderStates);
	}
	else
	{
		renderStates.transform.translate(getPosition());
		renderTarget.draw(mSprite, renderStates);
	}
}

}
