#include "States/state.hpp"
#include "Gui/guiManager.hpp"
#include "sharedData.hpp"
#include "Gui/Widgets/button.hpp"
#include "Input/actionManager.hpp"

namespace WhitE {

class TestState : public State
{
public:
	TestState(SharedData& data)
		:State(data)
		, mGuiManager(data.mWindow.getRenderWindow(), data.mWindow.getRenderWindow().getView())
	{}

	void onPop() override
	{}

	void onPush() override
	{
		auto* widget = mGuiManager.createWidget<gui::Button>("button");
		widget->setPercentagePosition(sf::Vector2f(0.f, 0.f));
		widget->setPercentageSize(sf::Vector2f(10.f, 5.f));
	}

	void draw() const override
	{	
		sf::RectangleShape rect;
		rect.setPosition(300.f, 100.f);
		rect.setSize(sf::Vector2f(500.f, 250.f));
		rect.setFillColor(sf::Color::Red);
		mGuiManager.draw();
	}

	void input() override
	{
		if (ActionManager::isActionPressed("changeSize"))
		{
			auto* widget = mGuiManager.get("button");
			auto position = widget->getPosition();
			widget->setPosition(position + sf::Vector2f(10.f, 10.f));
		}
		else if (ActionManager::isActionPressed("changeSizePercent"))
		{
			auto* widget = mGuiManager.get("button");
			auto position = widget->getPercentPosition();
			widget->setPercentagePosition(position + sf::Vector2f(1.f, 1.f));
		}
	}

	void update(const sf::Time& deltaTime) override
	{}

private:
	gui::GuiManager mGuiManager;
};

}
