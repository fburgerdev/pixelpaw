-- premake5.lua
ROOT = ".."
-- workspace
workspace "wndw"
   -- build options
   configurations { "debug", "release", "dist" }
   -- startproject
   startproject "test"
   -- cpp
   language "C++"
   cppdialect "C++Latest"
   -- debug
   debugger "GDB"
   -- config
   -- config :: debug
   filter "configurations:debug"
      symbols "On"
      defines { "CONFIG_DEBUG" }
   -- config :: fast
   filter "configurations:release"
      optimize "On"
      defines { "CONFIG_RELEASE" }
      linkoptions{ "-Ofast" }
   -- config :: dist
   filter "configurations:dist"
      optimize "On"
      defines { "CONFIG_DIST" }
      linkoptions { "-Ofast" }
-- project lib
project "wndw"
   -- static library
   kind "StaticLib"
   -- include directories
   includedirs {
      ROOT,
      ROOT .. "/src",
      ROOT .. "/modules/*/include",
      ROOT .. "/vendor/*/include"
   }
   -- files
   files {
      ROOT .. "/src/**",
   }
   -- binaries
   targetdir(ROOT .. "/lib/%{cfg.buildcfg}")
   objdir(ROOT .. "/bin/%{cfg.system}_%{cfg.buildcfg}")
-- tests :: PROJECT_NAME
project "test"
   -- console
   kind "ConsoleApp"
   -- include directories
   includedirs {
      ROOT .. "/include",
      ROOT .. "/src",
      ROOT .. "/modules/*/include",
      ROOT .. "/vendor/*/include"
   }
   -- library directories
   libdirs {
      ROOT .. "/lib/%{cfg.buildcfg}",
      ROOT .. "/modules/*/lib/%{cfg.buildcfg}",
      ROOT .. "/vendor/*/lib/%{cfg.buildcfg}"
   }
   -- files
   files {
      ROOT .. "/tests/test.cpp",
		--[[ INSERT ADDITIONAL FILES HERE ]]
   }
   -- links
   links { "wndw", "vecmath", "glfw3", "GLEW", --[[ INSERT ADDITIONAL LINKS HERE ]] }
   -- binaries
   targetdir(ROOT .. "/bin/tests/%{cfg.system}_%{cfg.buildcfg}")
   objdir(ROOT .. "/bin/tests/%{cfg.system}_%{cfg.buildcfg}/obj")