#include "ECS/system.hpp"

namespace WhitE::sys {

System::System(entt::registry& registry)
	:mRegistry(registry)
{
}

}