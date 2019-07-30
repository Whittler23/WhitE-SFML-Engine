printf ""
printf "For now project configuration is only availible when using Visual Studio"
printf "Building WhitE project using Premake..."
printf ""

workspace "WhitE"
    architecture "x86"
    location "../../"
    
    configurations {
        "Debug",
        "Release"
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
            "sfml-network-s-d",
            "sfml-window-s-d",
            "sfml-system-s-d"
        }

    filter{ "configurations:Release" }
        optimize "On"

        links{
            "sfml-graphics-s",
            "sfml-audio-s", 
            "sfml-network-s",
            "sfml-window-s",
            "sfml-system-s"
        }

    filter{ "system:Windows" }
        defines{ "WE_WINDOWS" }

    filter{ "system:Unix" }
        defines{ "WE_LINUX" }

    filter{}