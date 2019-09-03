#pragma once

#include <SFML/Graphics.hpp>

#include <string>
#include <list>

namespace WhitE {

class Entity
{
public:
	Entity(const std::string& name);

	void updateObjects(const sf::Time& deltaTime);
	void inputObjects();

	void addChild(std::unique_ptr<Entity> entity);
	void removeChild(const std::string& name);
	void removeChild(Entity* entity);
	void changeParentOfChild(Entity* child, Entity* newParent);

	auto getChild(const std::string& name) const->Entity &;
	auto getChildren() const -> const std::list<std::unique_ptr<Entity>>& { return mChildren; }
	auto getParent() const -> Entity* { return mParent; }
	auto getName() const -> std::string { return mName; }

	void setName(const std::string& name) { mName = name; }
	void setParent(Entity* parent) { mParent = parent; }

protected:
	virtual void update(const sf::Time& deltaTime);
	void updateChildren(const sf::Time& deltaTime);
	virtual void input();
	void inputChildren();

private:
	std::string mName;
	std::list<std::unique_ptr<Entity>> mChildren;
	Entity* mParent;
};

}