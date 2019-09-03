#pragma once

#include "Gui/stateGuiManager.hpp"

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include <vector>

namespace WhitE {

class Entity;
struct SharedData;

class BaseState
{
public:
	BaseState(SharedData& sharedData);
	virtual ~BaseState();

	virtual void onPop() = 0;
	virtual void onPush() = 0;

	virtual void draw() const = 0;
	virtual void input() = 0;
	virtual void update(const sf::Time& deltaTime) = 0;

	bool shouldPop() { return mShouldPop; }
	bool getTransparent() { return mTransparent; }
	bool getTranscendent() { return mTrandescend; }

protected:
	void setTransparent(const bool transparent) { mTransparent = transparent; }
	void setTranscendent(const bool transcendent) { mTrandescend = transcendent; }
	void setShouldPop(const bool shouldPop) { mShouldPop = shouldPop; }

	auto getSharedData() const -> SharedData & { return mSharedData; }
	auto getRenderTarget() const -> sf::RenderTarget & { return mRenderTarget; }

	float getTime() const { return mStateTimer.getElapsedTime().asSeconds(); }

private:
	SharedData& mSharedData;
	sf::RenderTarget& mRenderTarget;
	sf::Clock mStateTimer;
	bool mTransparent;
	bool mTrandescend;
	bool mShouldPop;

protected:
	StateGuiManager mStateGuiManager;
	std::list<std::unique_ptr<Entity>> mEntities;

};

}
