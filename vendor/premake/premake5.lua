printf ""
printf "For now project configuration is only availible when using Visual Studio"
printf "Building WhitE project using Premake..."
printf ""

workspace "WhitE"
    architecture "x86"
    location "../../"
	cppdialect "C++17"
    
    configurations {
        "Debug",
        "Release",
		"Tests"
    }
    
project "WhitE"
    language "C++"
    kind "ConsoleApp"

    targetdir "../../bin/bin/%{cfg.buildcfg}/" 
	objdir "../../bin/obj/%{cfg.buildcfg}/" 

    files {
         "../../src/**.cpp",
         "../../src/**.hpp",
		 "../../src/**.inl"
    }

    defines { "SFML_STATIC" }

    libdirs { "../../vendor/SFML/lib" }

    includedirs{
        "../../src",
        "../../vendor/SFML/include"
    }

    links{
        "opengl32.lib",
        "winmm.lib",
        "gdi32.lib",
        "freetype.lib",
        "flac.lib",
        "vorbisenc.lib",
        "vorbisfile.lib",
        "vorbis.lib",
        "ogg.lib",
        "openal32.lib"
    }

    filter{ "configurations:Debug" }
        symbols "On"

        links{
            "sfml-graphics-s-d",
            "sfml-audio-s-d",
            "sfml-window-s-d",
            "sfml-system-s-d"
        }

    filter{ "configurations:Release" }
        optimize "On"

        links{
            "sfml-graphics-s",
            "sfml-audio-s", 
            "sfml-window-s",
            "sfml-system-s"
        }
		
		defines{ "WE_RELEASE" }

		
    filter{ "system:Windows" }
        defines{ "WE_WINDOWS" }

    filter{ "system:Unix" }
        defines{ "WE_LINUX" }

    filter{}
	
	
project "Tests"
    location "../../"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"

    targetdir ("../../testsFiles/testBin/bin/")
	objdir ("../../testsFiles/testBin/obj/")
    
    includedirs{
        "../../src",
        "../../vendor/SFML/include",
        "../../vendor/catch2"
    }

    libdirs{"../../vendor/SFML/lib"}

    files{
        "../../src/**.hpp",
        "../../src/**.cpp",
        "../../src/**.inl",
        "../../testsFiles/tests/**.hpp",
        "../../testsFiles/tests/**.cpp"
    }
    
    removefiles{
        "../../src/main.cpp"
    }

    links{
        "opengl32.lib",
        "winmm.lib",
        "gdi32.lib",
        "freetype.lib",
        "flac.lib",
        "vorbisenc.lib",
        "vorbisfile.lib",
        "vorbis.lib",
        "ogg.lib",
        "openal32.lib"
    }

    defines{"SFML_STATIC"}

    filter "configurations:Debug or Tests"
        symbols "On"

        links{
            "sfml-graphics-s-d",
            "sfml-audio-s-d",
            "sfml-window-s-d",
            "sfml-system-s-d"
        }
		
		defines{"WE_TESTS"}

    filter{"configurations:Release"}
        optimize "On"

        links{
            "sfml-graphics-s",
            "sfml-audio-s", 
            "sfml-window-s",
            "sfml-system-s"
        }
        
    filter "system:Windows"
        defines{"WE_WINDOWS"}

    filter "system:Unix"
        defines{"WE_LINUX"}

    filter{}