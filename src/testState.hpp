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
		getSharedData().getTextures().load("buttonTexture", "resources/textures/button.png");
		sf::Texture& buttonTexture = getSharedData().getTextures().get("buttonTexture");
		mGuiManager.addWidget("testWidget", std::make_unique<gui::Widget>());
		mGuiManager.addWidget("button", std::make_unique<gui::Button>());
		mGuiManager.addWidget("button2", std::make_unique<gui::Button>());
		mGuiManager.get("button")->setPercentagePosition(sf::Vector2f(0.f, 0.f));
		mGuiManager.get("button")->setPercentageSize(sf::Vector2f(10.f, 5.f));
		auto& button2 = dynamic_cast<gui::Button&>(*mGuiManager.get("button2"));
		button2.setTexture(buttonTexture);
		button2.setPercentagePosition(sf::Vector2f(40.f, 30.f));

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
