-- https://premake.github.io/docs/What-Is-Premake
workspace "Pocket Monster"
   configurations { "Debug", "Release" }
   --location "game"

project "Sting Engine"
   basedir "src/se"
   kind "StaticLib"
   

   language "C++"
   cppdialect "C++23"
   files { "src/se/**.h", "src/se/**.cpp" }

   architecture ("x64")
   targetdir ("building")
   includedirs {
      "include"
   } 

   libdirs {
       "libs",
      }

   links {"winmm", "gdi32", "opengl32", "raylib"}  


   filter { "configurations:Debug" }
      defines { "DEBUG" }
      symbols "On"

   filter { "configurations:Release" }
      defines { "NDEBUG" }
      optimize "On"
------------------------------------------------------------------------
------------------------------------------------------------------------
project "Pocket Monster"
   basedir "src/game/"
   kind "ConsoleApp"
   language "C++"
   cppdialect "C++23"
   files { "src/game/**.h", "src/game/**.cpp" }
   targetdir ("game")
   architecture ("x64")

   includedirs {
      "include",
      "src/se"
   } 

   libdirs {
       "libs",
       "building"
      }
   
   links {"winmm", "gdi32", "opengl32", "raylib", "Sting Engine"}  

   filter { "configurations:Debug" }
      defines { "DEBUG" }
      symbols "On"

   filter { "configurations:Release" }
      defines { "NDEBUG" }
      optimize "On"