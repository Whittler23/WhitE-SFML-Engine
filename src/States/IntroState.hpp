#pragma once

#include "States/BaseState.hpp"

#include <SFML/Graphics.hpp>

namespace WhitE {

class ResourceHolder;

class IntroState : public BaseState
{
public:
	IntroState(sf::RenderWindow& win, ResourceHolder& rh);
	~IntroState();

	void draw() const override;
	void update(const sf::Time& deltaTime) override;

	void onPush() override;
	void onPop() override;

private:
	sf::RenderTarget& mRenderTarget;
	ResourceHolder& mResources;
	sf::Sprite mSplash;
};

}