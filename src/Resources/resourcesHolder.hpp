#pragma once

#include "Resources/resourcesManager.hpp"

#include "Resources/resourcesManager.inl"

#include <SFML/Audio.hpp>

namespace WhitE {


class ResourceHolder
{
public:
	ResourceHolder();

	auto getTextureHolder() const ->  const	ResourcesManager<sf::Texture>& { return mTextureHolder; }
	auto getSoundHolder() const -> const ResourcesManager<sf::SoundBuffer>& { return mSoundHolder; }
	auto getFontHolder() const -> const ResourcesManager<sf::Font>& { return mFontHolder; }

private:
	ResourcesManager<sf::Texture> mTextureHolder;
	ResourcesManager<sf::SoundBuffer> mSoundHolder;
	ResourcesManager<sf::Font> mFontHolder;

};


}
