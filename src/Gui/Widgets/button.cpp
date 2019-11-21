#include "button.hpp"
#include "Gui/Widgets/button.hpp"

namespace WhitE::gui{

Button::Button()
	:mHasTexture(false)
{
	buttonBody.setPosition(sf::Vector2f(1.f, 1.f));
	buttonBody.setSize(sf::Vector2f(1.f, 1.f));
}

void Button::draw(sf::RenderTarget& renderTarget, const sf::RenderStates& renderStates) const
{
	if (!mHasTexture)
	{
		sf::Vector2f size(buttonBody.getGlobalBounds().width, buttonBody.getGlobalBounds().height);


		sf::Transform transrom;
		transrom.translate(getPosition());
		sf::Vector2f scale = sf::Vector2f(getSize().x / buttonBody.getGlobalBounds().width, getSize().y / buttonBody.getGlobalBounds().height);
		transrom.scale(scale);
		renderTarget.draw(buttonBody, sf::RenderStates(transrom));
	}
}

}
