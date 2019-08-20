#pragma once

#include "States/baseState.hpp"

#include <SFML/Graphics.hpp>

namespace WhitE {

class ResourcesHolder;

class IntroState : public BaseState
{
public:
	IntroState(SharedData& sharedData);
	~IntroState();

	void draw() const override;
	void input() override;
	void update(const sf::Time& deltaTime) override;

	void onPush() override;
	void onPop() override;

	auto getSharedData() const -> SharedData & { return mSharedData; }

private:
	SharedData& mSharedData;
	sf::Sprite mSplash;
	sf::Text mText;
};

}