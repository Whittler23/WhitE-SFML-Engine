#pragma once

#include "Objects/drawableGameObject.hpp"
#include "sharedData.hpp"
#include "Input/actionManager.hpp"
#include "Renderer/renderer.hpp"

namespace WhitE {

class Player : public DrawableGameObject
{
public:
	Player(SharedData& sharedData)
		:DrawableGameObject(sharedData, LayerType::KinematicObjects, "Player")
	{
		init();
	}

	~Player()
	{

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
		getSharedData().mResourcesHolder.getTextureHolder().load("textTexture", "resources/textures/text.png");
		mSprite.setTexture(getSharedData().mResourcesHolder.getTextureHolder().get("textTexture"));
	}

	void draw(sf::RenderTarget& rt, sf::RenderStates rs) const override
	{
		rt.draw(mSprite);
	}

	void input() override
	{
		if (ActionManager::isActionJustPressed("Up"))
			move(Direction::Up);
		else if (ActionManager::isActionJustPressed("Down"))
			move(Direction::Down);
		else if (ActionManager::isActionJustPressed("Left"))
			move(Direction::Left);
		else if (ActionManager::isActionJustPressed("Right"))
			move(Direction::Right);
		else
			move(Direction::None);
	}

	void update(const sf::Time& time) override
	{

	}

	void move(Direction dir)
	{
		auto position = mSprite.getPosition();
		switch (dir)
		{
		case Direction::Up:
			setPosition(position + sf::Vector2f(0.f, -10.f));
			break;
		case Direction::Down:
			setPosition(position + sf::Vector2f(0.f, 10.f));
			break;
		case Direction::Left:
			setPosition(position + sf::Vector2f(-10.f, 0.f));
			break;
		case Direction::Right:
			setPosition(position + sf::Vector2f(10.f, 0.f));
			break;
		case Direction::None:
			break;
		}
	}

};

}