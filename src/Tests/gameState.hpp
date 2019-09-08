#pragma once

#include "States/BaseState.hpp"
#include "Input/actionManager.hpp"
#include "sharedData.hpp"
#include "Logger/logs.hpp"

#include "Tests/player.hpp"
#include "Tests/background.hpp"

#include <SFML/Graphics.hpp>

#include <iostream>

namespace WhitE {

struct SharedData;

class GameState : public BaseState
{
public:
	GameState(SharedData& sharedData, const sf::Vector2f& viewSize);

	void onPop();
	void onPush();

	void update(const sf::Time& deltaTime);
	void input();
	void draw() const;
};

}