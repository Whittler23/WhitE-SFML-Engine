#pragma once

#include "Resources/resourcesManager.hpp"

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include <vector>

namespace WhitE {

struct SharedData;
class GameObject;

class BaseState
{
public:
	BaseState();
	virtual ~BaseState();

	virtual void onPop() = 0;
	virtual void onPush() = 0;

	virtual void draw() const = 0;
	virtual void input() = 0;
	virtual void update(const sf::Time& deltaTime) = 0;

	float getTime() const	{ return mStateTimer.getElapsedTime().asSeconds(); }
	bool getTransparent()	{ return mTransparent; }
	bool getTranscendent()	{ return mTrandescend; }
	bool shouldPop()		{ return mShouldPop; }
	auto getRoot() const -> GameObject& { return *mRootObject; }

	void setTransparent(const bool transparent)		{ mTransparent = transparent; }
	void setTranscendent(const bool transcendent)	{ mTrandescend = transcendent; }
	void setShouldPop(const bool shouldPop)			{ mShouldPop =  shouldPop; }

private:
	std::unique_ptr<GameObject> mRootObject;
	sf::Clock mStateTimer;
	bool mTransparent;
	bool mTrandescend;
	bool mShouldPop;
};

}
