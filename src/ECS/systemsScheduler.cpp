#include "ECS/systemsScheduler.hpp"

namespace WhitE {

SystemsScheduler::SystemsScheduler(entt::registry& registry)
	:mRegistry(registry)
{
}

void SystemsScheduler::update(const sf::Time deltaTime)
{
	for (const auto& system : mSystemsMap)
		system.second->update(deltaTime);
}

}
