#include <catch.hpp>

#include "Resources/resourcesHolder.hpp"

namespace WhitE {

TEST_CASE("ResourceHolder class can operate on resources")
{
	ResourceHolder resourceHolder;

	SECTION("Add resources and check if they are present")
	{
		resourceHolder.getFontHolder().load("G:/WhitE/testsFiles/testsResources/testFont.ttf");
		resourceHolder.getTextureHolder().load("G:/WhitE/testsFiles/testsResources/testLogo.png");
		resourceHolder.getSoundHolder().load("G:/WhitE/testsFiles/testsResources/testSound.wav");

		CHECK(resourceHolder.getFontHolder().doesExist("G:/WhitE/testsFiles/testsResources/testFont.ttf"));
		CHECK(resourceHolder.getTextureHolder().doesExist("G:/WhitE/testsFiles/testsResources/testLogo.png"));
		CHECK(resourceHolder.getSoundHolder().doesExist("G:/WhitE/testsFiles/testsResources/testSound.wav"));
	}

	SECTION("Add resources, delete them and check if they are present")
	{
		resourceHolder.getFontHolder().load("G:/WhitE/testsFiles/testsResources/testFont.ttf");
		resourceHolder.getTextureHolder().load("G:/WhitE/testsFiles/testsResources/testLogo.png");
		resourceHolder.getSoundHolder().load("G:/WhitE/testsFiles/testsResources/testSound.wav");

		CHECK(resourceHolder.getFontHolder().doesExist("G:/WhitE/testsFiles/testsResources/testFont.ttf"));
		CHECK(resourceHolder.getTextureHolder().doesExist("G:/WhitE/testsFiles/testsResources/testLogo.png"));
		CHECK(resourceHolder.getSoundHolder().doesExist("G:/WhitE/testsFiles/testsResources/testSound.wav"));

		resourceHolder.getFontHolder().free("G:/WhitE/testsFiles/testsResources/testFont.ttf");
		resourceHolder.getTextureHolder().free("G:/WhitE/testsFiles/testsResources/testLogo.png");
		resourceHolder.getSoundHolder().free("G:/WhitE/testsFiles/testsResources/testSound.wav");

		CHECK(!resourceHolder.getFontHolder().doesExist("G:/WhitE/testsFiles/testsResources/testFont.ttf"));
		CHECK(!resourceHolder.getTextureHolder().doesExist("G:/WhitE/testsFiles/testsResources/testLogo.png"));
		CHECK(!resourceHolder.getSoundHolder().doesExist("G:/WhitE/testsFiles/testsResources/testSound.wav"));
	}

}

}