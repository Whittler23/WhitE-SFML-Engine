#include "Renderer/camera.hpp"
#include "Logger/logs.hpp"
#include "Utilities/cast.hpp"

#include "Tests/player.hpp"

namespace WhitE {

Camera::Camera(sf::RenderTarget& renderTarget)
	:mRenderTarget(renderTarget)
	,mView(renderTarget.getView())
	//,mCameraTarget(nullptr)
{
	WE_CORE_INFO("Camera initialized with view size: " + Cast::toString(mView.getSize()));
	WE_CORE_INFO("Camera center: " + Cast::toString(mView.getCenter()));
}

void Camera::update(const sf::Time& deltaTime)
{
	//if(mCameraTarget != nullptr)
	//	setViewCenter(mCameraTarget->getPosition());

	mRenderTarget.setView(mView);
}

void Camera::zoom(const float zoomFactor)
{
	mView.zoom(zoomFactor);
}

void Camera::setViewSize(const sf::Vector2f& viewSize)
{
	mView.setSize(viewSize);
}

void Camera::setViewCenter(const sf::Vector2f viewCenter)
{
	mView.setCenter(viewCenter);
}

//void Camera::setCameraTarget(DrawableGameObject* object)
//{
//	mCameraTarget = object;
//}

//void Camera::resetCameraTarget()
//{
//	mCameraTarget = nullptr;
//}

auto Camera::getViewSize() const -> const sf::Vector2f
{
	return mView.getSize();
}

auto Camera::getView() const -> const sf::View &
{
	return mView;
}

}