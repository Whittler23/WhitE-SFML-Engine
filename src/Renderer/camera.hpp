#pragma once

#include <SFML/Graphics.hpp>

namespace WhitE {

class DrawableGameObject;

class Camera
{
public:
	Camera(sf::RenderTarget& renderTarget);

	void update(const sf::Time& deltaTime);

	void zoom(float zoomPercent);

	void setViewSize(const sf::Vector2f& viewSize);
	void setViewCenter(const sf::Vector2f viewCenter);

	void setCameraTarget(DrawableGameObject* object);
	void resetCameraTarget();

	auto getViewSize() const -> const sf::Vector2f;
	auto getView() const -> const sf::View &;
	auto getDefaultView() const -> const sf::View &;

private:
	sf::RenderTarget& mRenderTarget;
	sf::View mView;
	sf::View mDefaultView;
	DrawableGameObject* mCameraTarget;

};

}