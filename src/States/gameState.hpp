#pragma once

#include "States/BaseState.hpp"
#include "Objects/drawableGameObject.hpp"
#include "Input/actionManager.hpp"
#include "sharedData.hpp"
#include "Logger/logs.hpp"

namespace WhitE {

class Player : public DrawableGameObject
{
public:
	Player(Renderer& renderer)
		:DrawableGameObject(renderer, LayerType::KinematicObjects, "Player")
		,playerShape(sf::Quads, 4)
	{
		playerShape.setPrimitiveType(sf::Quads);
		init();
	}

	void init();

	void update(const sf::Time& deltaTime);
	void draw(sf::RenderTarget& renderTarget, sf::RenderStates renderStates) const override;

private:
	sf::VertexArray playerShape;

};

void Player::init()
{
	ActionManager::addAction("MoveUp", sf::Keyboard::W);
	ActionManager::addAction("MoveDown", sf::Keyboard::S);
	ActionManager::addAction("MoveLeft", sf::Keyboard::A);
	ActionManager::addAction("MoveRight", sf::Keyboard::D);

	playerShape[0].color = sf::Color::Red;
	playerShape[1].color = sf::Color::Red;
	playerShape[2].color = sf::Color::Red;
	playerShape[3].color = sf::Color::Red;
}

void Player::draw(sf::RenderTarget& renderTarget, sf::RenderStates renderStates) const
{
	sf::RectangleShape sf(sf::Vector2f(200.f, 300.f));
	renderTarget.draw(playerShape);
	renderTarget.draw(sf);
}

void Player::update(const sf::Time& deltaTime)
{
	if (ActionManager::isActionPressed("MoveDown"))
	{
		WE_INFO("Player move down!");
	//	setPosition(sf::Vector2f(getPosition().x, getPosition().y+.1f * deltaTime.asMilliseconds()));
	}
}

//========================================================

struct SharedData;

class GameState : public BaseState
{
public:
	GameState(SharedData& sharedData)
		:mSharedData(sharedData)
	{
	}

	void onPop()
	{
		mSharedData.mRenderer.clearDrawables();
		WE_CORE_INFO("GameState Popped!");
	}
	void onPush()
	{
		WE_CORE_INFO("GameState Pushed!");
		getRoot().addChild(std::make_unique<Player>(mSharedData.mRenderer));
	}

	void onCover()
	{
		mSharedData.mRenderer.clearDrawables();
	}

	void draw() const
	{

	}

	void input()
	{
		getRoot().input();
	}
	void update(const sf::Time& deltaTime)
	{
		getRoot().update(deltaTime);
	}

private:
	SharedData& mSharedData;
};

}