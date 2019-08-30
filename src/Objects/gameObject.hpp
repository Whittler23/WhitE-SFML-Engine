#pragma once

#include <SFML/System.hpp>

#include <string>
#include <list>

namespace WhitE {

class GameObject
{
public:
	GameObject(const std::string& name);

	virtual void update(const sf::Time& deltaTime);
	virtual void input();

	void addChild(std::unique_ptr<GameObject> gameObject);
	void removeChild(const std::string& name);
	void removeChild(GameObject* gameObject);
	void changeParentOfChild(GameObject* child, GameObject* newParent);

	auto getChild(const std::string& name) const->GameObject &;
	auto getChildren() const -> const std::list<std::unique_ptr<GameObject>>& { return mChildren; }
	auto getParent() const -> GameObject* { return mParent; }
	auto getName() const -> std::string { return mName; }

	void setName(const std::string& name) { mName = name; }
	void setParent(GameObject* parent) { mParent = parent; }

private:
	std::string mName;
	std::list<std::unique_ptr<GameObject>> mChildren;
	GameObject* mParent;
};

}