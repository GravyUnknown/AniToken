workspace "AniToken"
  configurations { "Debug_64", "Release_64", "Debug_32", "Release_32" }

project "AniToken"
  kind "ConsoleApp"
  language "C++"
  cppdialect "C++23"
  location "AniToken"
  files { "Anitoken/*.cpp", "AniToken/*.h" }
  warnings "Extra"
  fatalwarnings "All"
  filter "configurations:Debug_64"
    defines { "DEBUG" }
    symbols "On"
    architecture "x64"
  filter "configurations:Release_64"
    defines { "NDEBUG" }
    optimize "On"
    architecture "x64"
  filter "configurations:Debug_32"
    defines { "DEBUG" }
    symbols "On"
    architecture "x86"
  filter "configurations:Release_32"
    defines { "NDEBUG" }
    optimize "On"
    architecture "x86"
