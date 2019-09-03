#include "Objects/entity.hpp"
#include "Logger/logs.hpp"
#include "Objects/drawableGameObject.hpp"

namespace WhitE {

Entity::Entity(const std::string& name)
	:mName(name)
{
}

void Entity::update(const sf::Time& deltaTime)
{
}

void Entity::input()
{
}

}