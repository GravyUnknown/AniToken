workspace "AniToken"
configurations { "Debug", "Release" }

project "AniToken"
kind "ConsoleApp"
language "C++"
cppdialect "C++23"
location "AniToken"
files { "Anitoken/*.cpp", "AniToken/*.h" }
filter "configurations:Debug"
defines { "DEBUG" }
symbols "On"
filter "configurations:Release"
defines { "NDEBUG" }
optimize "On"
