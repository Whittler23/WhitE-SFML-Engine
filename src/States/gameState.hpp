#pragma once

#include "States/BaseState.hpp"
#include "Objects/drawableGameObject.hpp"
#include "Input/actionManager.hpp"
#include "sharedData.hpp"
#include "Logger/logs.hpp"

#include <SFML/Graphics.hpp>

namespace WhitE {

class Background : public DrawableGameObject
{
public:
	Background(StateRenderer& stateRenderer, SharedData& sharedData)
		:DrawableGameObject(stateRenderer, sharedData, LayerType::Background, "Background")
	{
		init();
	}

	void init()
	{
		getSharedData().mResourcesHolder.getTextureHolder().load("resources/textures/Background.png");
		mSprite.setTexture(getSharedData().mResourcesHolder.getTextureHolder().get("resources/textures/Background.png"));
		
	}

	void draw(sf::RenderTarget& rt, sf::RenderStates rs) const override
	{
		rt.draw(mSprite);
	}

private:
	sf::Sprite mSprite;
};

class Player : public DrawableGameObject
{
public:
	Player(StateRenderer& stateRenderer, SharedData& sharedData)
		:DrawableGameObject(stateRenderer, sharedData, LayerType::KinematicObjects, "Player")
	{
		init();
	}

	enum class Direction
	{
		None, Up, Down, Left, Right
	};

	void init()
	{
		ActionManager::addAction("Up", sf::Keyboard::W);
		ActionManager::addAction("Down", sf::Keyboard::S);
		ActionManager::addAction("Left", sf::Keyboard::A);
		ActionManager::addAction("Right", sf::Keyboard::D);
		getSharedData().mResourcesHolder.getTextureHolder().load("resources/textures/text.png");
		mSprite.setTexture(getSharedData().mResourcesHolder.getTextureHolder().get("resources/textures/text.png"));
	}

	void draw(sf::RenderTarget& rt, sf::RenderStates rs) const override
	{
		rt.draw(mSprite);
	}

	void input() override
	{
		if (ActionManager::isActionJustPressed("Up"))
			setPosition(Direction::Up);
		else if (ActionManager::isActionJustPressed("Down"))
			setPosition(Direction::Down);
		else if (ActionManager::isActionJustPressed("Left"))
			setPosition(Direction::Left);
		else if (ActionManager::isActionJustPressed("Right"))
			setPosition(Direction::Right);
		else
			setPosition(Direction::None);
	}

	void update(const sf::Time& time) override
	{

	}

	void setPosition(Direction dir)
	{
		auto position = mSprite.getPosition();
		switch (dir)
		{
		case Direction::Up:
			mSprite.setPosition(position + sf::Vector2f(0.f, -.5f));
			break;
		case Direction::Down:
			mSprite.setPosition(position + sf::Vector2f(0.f, .5f));
			break;
		case Direction::Left:
			mSprite.setPosition(position + sf::Vector2f(-.5f, 0.f));
			break;
		case Direction::Right:
			mSprite.setPosition(position + sf::Vector2f(.5f, 0.f));
			break;
		case Direction::None:
			break;
		}
	}

private:
	sf::Sprite mSprite;

};

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
		getRoot().addChild(std::make_unique<Background>(mStateRenderer, getSharedData()));
		getRoot().addChild(std::make_unique<Player>(mStateRenderer, getSharedData()));

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