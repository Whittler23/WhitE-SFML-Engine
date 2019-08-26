#pragma once

#include "States/baseState.hpp"

#include <SFML/Graphics.hpp>

namespace WhitE {

struct SharedData;
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

};

}