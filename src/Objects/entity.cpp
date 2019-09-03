#include "Objects/entity.hpp"
#include "Logger/logs.hpp"
#include "Objects/drawableGameObject.hpp"

namespace WhitE {

Entity::Entity(const std::string& name)
	:mParent(nullptr)
	,mName(name)
{
}

void Entity::updateObjects(const sf::Time& deltaTime)
{
	update(deltaTime);
	updateChildren(deltaTime);
}

void Entity::inputObjects()
{
	input();
	inputChildren();
}

void Entity::update(const sf::Time& deltaTime)
{
}

void Entity::updateChildren(const sf::Time& deltaTime)
{
	for (auto& child : mChildren)
	{
		child->updateObjects(deltaTime);
	}
}

void Entity::input()
{
}

void Entity::inputChildren()
{
	for (auto& child : mChildren)
	{
		child->inputObjects();
	}
}

void Entity::addChild(std::unique_ptr<Entity> entity)
{
	entity->setParent(this);
	WE_CORE_INFO("\"" + entity->getName() + "\" was added as the child of \"" + getName() + "\"");
	mChildren.emplace_back(std::move(entity));
}

void Entity::removeChild(const std::string& nameOfObjectToRemove)
{
	for (auto it = mChildren.begin(); it != mChildren.end(); ++it)
		if ((*it)->getName() == nameOfObjectToRemove)
		{
			WE_CORE_INFO("\"" + (*it)->getName() + "\" which was child of \"" + getName() + "\" was removed");
			mChildren.erase(it);
			return;
		}

	WE_CORE_WARNING("\"" + nameOfObjectToRemove + "\" is not a child of \"" + getName() + "\" and could not be removed");
}

void Entity::removeChild(Entity* entityToRemove)
{
	for (auto it = mChildren.begin(); it != mChildren.end(); ++it)
		if (it->get() == entityToRemove)
		{
			mChildren.erase(it);
			WE_CORE_INFO("\"" + (*it)->getName() + "\" which was child of \"" + mName + "\" was removed");
			return;
		}

	WE_CORE_WARNING("\"" + entityToRemove->getName() + "\" is not a child of \"" + mName + "\" and could not be removed");
}

auto Entity::getChild(const std::string& name) const -> Entity&
{
	for (auto& child : mChildren)
		if (child->getName() == name)
			return *child.get();

	throw std::runtime_error("\"" + name + "\" is not a child of \"" + mName + "\" and could not be removed");
}

void Entity::changeParentOfChild(Entity* child, Entity* newParent)
{
	for (auto it = mChildren.begin(); it != mChildren.end(); ++it)
		if (it->get() == child)
		{
			newParent->addChild(std::move(*it));
			mChildren.erase(it);
			break;
		}

	WE_CORE_INFO("Entity \"" + child->getName() + "\" became a child of the \"" + newParent->getName() + "\". It was a child of the \"" + mName + "\"");
}

}