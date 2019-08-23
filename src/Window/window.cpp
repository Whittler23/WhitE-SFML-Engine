#include "Input/mouseManager.hpp"
#include "Window/window.hpp"
#include "Logger/logs.hpp"

namespace WhitE {

	Window::Window(const std::string name, bool winStyle, sf::Vector2u size)
		:mShouldClose(false)
	{
		initializeWindow();
	}

	Window::Window()
		: mShouldClose(false)
	{
		initializeWindow();
	}

	void Window::initializeWindow()
	{
		auto style = (mProperties.mWinFllscr ? sf::Style::Fullscreen : sf::Style::Default);
		mGameWindow.create(sf::VideoMode(mProperties.mWinSize.x, mProperties.mWinSize.y), mProperties.mWinTitle, style);
	}

	void Window::input()
	{
		sf::Event windowEvent;

		while(getRenderWindow().pollEvent(windowEvent))
		{ 
			switch (windowEvent.type)
			{
			case sf::Event::Closed:
				WE_CORE_INFO("Closing WhitE Engine!");
				mShouldClose = true;
				break;

			case sf::Event::LostFocus:
				WE_CORE_INFO("Window lost focus");
				break;

			case sf::Event::GainedFocus:
				WE_CORE_INFO("Window gained focus");
				break;

			case sf::Event::Resized:
				WE_CORE_INFO("Resized! Window size: x" + std::to_string(getWindowWidth())
					+ " y" + std::to_string(getWindowHeight()));
				break;

			case sf::Event::MouseButtonPressed:
				sf::Vector2i mouseClickPosition = sf::Mouse::getPosition(getRenderWindow());
				MouseManager::readMouseClickPosition(mouseClickPosition);
				WE_CORE_INFO("Clicked! Mouse position: x" + std::to_string(mouseClickPosition.x) 
					+ " y" + std::to_string(mouseClickPosition.y));
				break;
			}
		}
	}

	void Window::update()
	{
		MouseManager::readMousePosition(sf::Mouse::getPosition(getRenderWindow()));
	}

	void Window::draw(sf::Drawable& drawable)
	{

	}

}