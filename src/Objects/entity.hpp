#pragma once

#include <SFML/Graphics.hpp>

#include <string>
#include <list>

namespace WhitE {

struct SharedData;
class ResourcesHolder;

class Entity : public sf::Drawable
{
public:
	Entity(SharedData& sharedData, const std::string& name);

	virtual void update(const sf::Time& deltaTime);
	virtual void input();

	auto getName() const -> std::string { return mName; }
	void setName(const std::string& name) { mName = name; }

	sf::Vector2f getScale() const;
	sf::Vector2f getPosition() const;
	float getRotation() const;
	bool getVisibility() const;

protected:
	virtual void setPosition(const sf::Vector2f& position);
	virtual void setScale(const sf::Vector2f& scale);
	virtual void setRotation(const float rotationAngle);
	virtual void setVisibility(const bool visibility);
	virtual void rotate(const float angle);
	auto getSharedData()->SharedData &;

protected:
	sf::Sprite mSprite;

private:
	SharedData& mSharedData;
	std::string mName;
	sf::Vector2f mPosition;
	sf::Vector2f mScale;
	float mRotation;
	bool mVisibility;
};

}