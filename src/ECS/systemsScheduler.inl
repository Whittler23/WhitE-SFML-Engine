namespace WhitE {

template<typename System, typename... Args>
void SystemsScheduler::addSystem(int systemPriority, Args... arguments)
{
	mSystemsMap.insert(systemPriority, std::make_unique<System>(arguments));
}

}
