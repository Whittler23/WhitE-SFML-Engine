#pragma once

#include <SFML/Graphics.hpp>

namespace WhitE {

class Entity;

class Camera
{
public:
	Camera(sf::RenderTarget& renderTarget);

	void update(const sf::Time& deltaTime);

	void zoom(float zoomPercent);

	void setView(const sf::View& view);
	void setViewSize(const sf::Vector2f& viewSize);
	void setViewCenter(const sf::Vector2f viewCenter);

	void setCameraTarget(Entity* object);
	void resetCameraTarget();

	auto getViewSize() const -> const sf::Vector2f;
	auto getView() const -> const sf::View &;
	auto getDefaultView() const -> const sf::View &;

private:
	void applyView();

private:
	sf::RenderTarget& mRenderTarget;
	sf::View mView;
	sf::View mDefaultView;
	Entity* mCameraTarget;

};

}