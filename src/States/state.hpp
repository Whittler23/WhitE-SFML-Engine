#pragma once

#include "Gui/stateGuiManager.hpp"

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include <vector>

namespace WhitE {

struct SharedData;

class State
{
public:
	State(SharedData& sharedData);
	virtual ~State();

	virtual void onPop() = 0;
	virtual void onPush() = 0;

	virtual void draw() const = 0;
	virtual void input() = 0;
	virtual void update(const sf::Time& deltaTime) = 0;

	bool shouldPop() { return mShouldPop; }
	bool getTransparent() { return mTransparent; }
	bool getTranscendent() { return mTrandescend; }

	bool isNextStatePending() { return mNextState != nullptr; }
	std::unique_ptr<State> getNextState() { return std::move(mNextState); }

protected:
	void setNextState(std::unique_ptr<State> nextState) { mNextState = std::move(nextState); }
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
	std::unique_ptr<State> mNextState;

};

}
