#include "Input/mouseManager.hpp"
#include "Input/actionManager.hpp"
#include "Input/eventManager.hpp"
#include "window.hpp"
#include "Logger/logs.hpp"
#include "Utilities/cast.hpp"

namespace WhitE {

	Window::Window(const std::string name, bool winStyle, sf::Vector2u size)
		:mShouldClose(false)
		,mHasFocus(true)
		,mProperties(name, winStyle, size)
	{
		initializeWindow();
	}

	Window::Window()
		:mShouldClose(false)
		,mHasFocus(true)
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
		
	}

	void Window::updateEvents()
	{
		EventManager::clear();
		sf::Event event;

		while (getRenderWindow().pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::KeyPressed:
				EventManager::setIsKeyPressed(true);
				EventManager::setLastPressedKey(event.key.code);
				break;

			case sf::Event::KeyReleased:
				EventManager::setIsKeyReleased(true);
				EventManager::setLastReleasedKey(event.key.code);
				break;

			case sf::Event::MouseButtonPressed:
				EventManager::setIsButtonPressed(true);
				EventManager::setLastPressedButton(event.mouseButton.button);

				MouseManager::readMouseWindowClickPosition();
				MouseManager::readMouseWorldClickPosition();

				WE_CORE_INFO("Clicked! Mouse window position: " + Cast::toString(MouseManager::getLastMouseWindowClickPosition()));
				WE_CORE_INFO("Clicked! Mouse world position: " + Cast::toString(MouseManager::getLastMouseWorldClickPosition()));

				break;

			case sf::Event::MouseButtonReleased:
				EventManager::setIsButtonReleased(true);
				EventManager::setLastReleasedButton(event.mouseButton.button);
				break;

			case sf::Event::Closed:
				WE_CORE_INFO("Closing WhitE Engine!");
				mShouldClose = true;
				break;

			case sf::Event::LostFocus:
				WE_CORE_INFO("Window lost focus");
				mHasFocus = false;
				break;

			case sf::Event::GainedFocus:
				WE_CORE_INFO("Window gained focus");
				mHasFocus = true;
				break;

			case sf::Event::Resized:
				sf::FloatRect visableArea(0.f, 0.f, event.size.width, event.size.height);
				mGameWindow.setView(sf::View(visableArea));

				WE_CORE_INFO("Resized! Window size: x" + std::to_string(getWindowWidth())
					+ " y" + std::to_string(getWindowHeight()));
				break;
			}
		}
	}

	void Window::update()
	{
		sf::Vector2i mouseWindowPosition = sf::Mouse::getPosition(getRenderWindow());
		MouseManager::readMouseWindowPosition(mouseWindowPosition);

		sf::Vector2f mouseWorldPosition = mGameWindow.mapPixelToCoords(mouseWindowPosition);
		MouseManager::readMouseWorldPosition(mouseWorldPosition);
	}

	void Window::draw(sf::Drawable& drawable)
	{

	}

}