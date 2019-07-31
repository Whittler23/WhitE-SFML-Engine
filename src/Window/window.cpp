#include "Window/window.hpp"

namespace WhitE {

	Window::Window(WindowProperties)
	{
		initializeWindow();
	}


	Window::Window()
	{
		initializeWindow();
	}

	void Window::initializeWindow()
	{
		auto style = (mProperties.mWinFullscreen ? sf::Style::Fullscreen : sf::Style::Default);
		mGameWindow.create(sf::VideoMode(mProperties.mWinSize.x, mProperties.mWinSize.y), mProperties.mWindowTitle, style);
	}



	void Window::update()
	{

	}

	void Window::draw()
	{
		mGameWindow.clear();
		mGameWindow.display();
	}

}