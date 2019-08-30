#pragma once

#include "Objects/drawableGameObject.hpp"
#include "sharedData.hpp"
#include "Input/actionManager.hpp"
#include "Renderer/renderer.hpp"

namespace WhitE {

class Player : public DrawableGameObject
{
public:
	Player(StateRenderer& stateRenderer, SharedData& sharedData)
		:DrawableGameObject(stateRenderer, sharedData, LayerType::KinematicObjects, "Player")
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
			mSprite.setPosition(position + sf::Vector2f(0.f, -10.f));
			break;
		case Direction::Down:
			mSprite.setPosition(position + sf::Vector2f(0.f, 10.f));
			break;
		case Direction::Left:
			mSprite.setPosition(position + sf::Vector2f(-10.f, 0.f));
			break;
		case Direction::Right:
			mSprite.setPosition(position + sf::Vector2f(10.f, 0.f));
			break;
		case Direction::None:
			break;
		}
	}

	sf::Vector2f getPosition()
	{
		return mSprite.getPosition();
	}

private:
	sf::Sprite mSprite;

};

}