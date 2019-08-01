#include "Window/window.hpp"

namespace WhitE {

	Window::Window(const std::string name, bool winStyle, sf::Vector2u size)
	{
		initializeWindow();
	}

	Window::Window()
	{
		initializeWindow();
	}

	void Window::initializeWindow()
	{
		auto style = (mProperties.mWinFllscr ? sf::Style::Fullscreen : sf::Style::Default);
		mGameWindow.create(sf::VideoMode(mProperties.mWinSize.x, mProperties.mWinSize.y), mProperties.mWinTitle, style);
	}

	void Window::update()
	{

	}

	void Window::draw(sf::Drawable& drawable)
	{
		mGameWindow.clear();
		mGameWindow.draw(drawable);
		mGameWindow.display();
	}

}