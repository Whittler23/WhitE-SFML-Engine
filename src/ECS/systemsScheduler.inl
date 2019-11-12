template<typename System, typename... Args>
void WhitE::SystemsScheduler::addSystem(int systemPriority, Args... arguments)
{
	mSystemsMap.insert(std::make_pair(systemPriority, std::make_unique<System>(mRegistry, arguments...)));
}
