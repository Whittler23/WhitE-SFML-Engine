#include "Renderer/camera.hpp"
#include "Logger/logs.hpp"
#include "Utilities/cast.hpp"

namespace WhitE {

Camera::Camera(sf::RenderTarget& renderTarget)
	:mRenderTarget(renderTarget)
	,mView(renderTarget.getView())
	,mDefaultView(renderTarget.getDefaultView())
{
	WE_CORE_INFO("Camera initialized with view size: " + Cast::toString(mView.getSize()));
	WE_CORE_INFO("Camera center: " + Cast::toString(mView.getCenter()));
}

void Camera::update(const sf::Time& deltaTime)
{

	applyView();
}

void Camera::zoom(float zoomPercent)
{
	zoomPercent /= 100.f;
	mView.zoom(zoomPercent);
	applyView();
}

void Camera::setView(const sf::View& view)
{
	mView = view;
	applyView();
}

void Camera::setViewSize(const sf::Vector2f& viewSize)
{
	mView.setSize(viewSize);
	applyView();
}

void Camera::setViewCenter(const sf::Vector2f viewCenter)
{
	mView.setCenter(viewCenter);
}

void Camera::applyView()
{
	mRenderTarget.setView(mView);
}

void Camera::resetCameraTarget()
{
}

auto Camera::getViewSize() const -> const sf::Vector2f
{
	return mView.getSize();
}

auto Camera::getView() const -> const sf::View &
{
	return mView;
}

auto Camera::getDefaultView() const -> const sf::View &
{
	return mDefaultView;
}

}