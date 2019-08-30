#pragma once

namespace WhitE {

class Button : public DrawableGameObject
{
public:
	Button(StateRenderer& stateRenderer, SharedData& sharedData, const sf::Vector2f& position, const std::string& text)
		:DrawableGameObject(stateRenderer, sharedData, LayerType::StaticObjects, "Button")
		,mButtonText(text, getSharedData().mResourcesHolder.getFontHolder().get("testFont"))
		,mPosition(position)
		,mIdleColor(50, 206, 209, 120)
		,mHoverColor(50, 206, 209, 200)
	{
		loadResources();
		init();
	}

	~Button()
	{

	}

	void loadResources()
	{
	}

	void init()
	{
		mButtonBackground.setPosition(mPosition);
		mButtonBackground.setSize(sf::Vector2f(160.f, 45.f));
		mButtonBackground.setFillColor(mIdleColor);

		mButtonText.setFont(getSharedData().mResourcesHolder.getFontHolder().get("testFont"));
		mButtonText.setCharacterSize(25);
		mButtonText.setPosition(
			mButtonBackground.getPosition().x + mButtonBackground.getSize().x /2 - mButtonText.getGlobalBounds().width/2.f, 
			mButtonBackground.getPosition().y + mButtonBackground.getSize().y / 2 - mButtonText.getGlobalBounds().height/2.f
		);
		mButtonText.move(sf::Vector2f(0, -5.f));
	}

	void input() override
	{
		if (mButtonBackground.getGlobalBounds().contains(sf::Vector2f(MouseManager::getMouseWindowPosition())))
			mButtonBackground.setFillColor(mHoverColor);
		else
			mButtonBackground.setFillColor(mIdleColor);
	}

	void draw(sf::RenderTarget& rt, sf::RenderStates) const override
	{
		rt.draw(mButtonBackground);
		rt.draw(mButtonText);
	}


private:
	sf::Color mIdleColor;
	sf::Color mHoverColor;
	sf::RectangleShape mButtonBackground;
	sf::Text mButtonText;
	sf::Vector2f mPosition;
};

}