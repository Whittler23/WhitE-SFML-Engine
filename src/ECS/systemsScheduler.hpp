#pragma once

#include "ECS/system.hpp"

#include <map>
#include <memory>

namespace WhitE {

class SystemsScheduler
{
public:
	SystemsScheduler(entt::registry& registry);

	void update(const sf::Time deltaTime);

	template<typename System, typename... Args>
	void addSystem(int systemPriority, Args... arguments);

private:
	std::map<int, std::unique_ptr<sys::System>, std::less<int> > mSystemsMap;
	entt::registry& mRegistry;
};

#include "ECS/systemsScheduler.inl"

}
