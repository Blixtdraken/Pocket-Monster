-- https://premake.github.io/docs/What-Is-Premake
workspace "Pocket Monster"
   architecture ("x64")
   configurations { "Debug", "Release" }
   --location "game"

project "Sting Engine"
   basedir "src/se"
   kind "StaticLib"
   

   language "C++"
   cppdialect "C++23"
   files { "src/se/**.h", "src/se/**.cpp" }

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
   debugdir "game"
   

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
      debugdir "game"
   filter { "configurations:Release" }
      defines { "NDEBUG" }
      optimize "On"
      debugdir "game"
------------------------------------------------------------------------
------------------------------------------------------------------------
project "Assets"
    basedir "game/project"
    files { "./game/assets/**" }
    kind "Utility"
    
    