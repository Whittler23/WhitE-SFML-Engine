#pragma once

#include "States/BaseState.hpp"
#include "Objects/drawableGameObject.hpp"
#include "Input/actionManager.hpp"
#include "sharedData.hpp"
#include "Logger/logs.hpp"

#include <SFML/Graphics.hpp>

namespace WhitE {

struct SharedData;

class GameState : public BaseState
{
public:
	GameState(SharedData& sharedData)
		:BaseState(sharedData)
	{
	}

	void onPop()
	{
		mStateRenderer.clearDrawables();
		WE_INFO("Game State popped from the stack");
	}
	void onPush()
	{
		WE_CORE_INFO("Game State pushed on the stack");
	}

	void draw() const
	{
		mStateRenderer.draw();
	}

	void input()
	{
		getRoot().input();
	}
	void update(const sf::Time& deltaTime)
	{
		getRoot().update(deltaTime);
	}

};

}