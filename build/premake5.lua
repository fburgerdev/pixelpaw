-- premake5.lua
ROOT = ".."
PRJ_NAME = "window" --[[ MODIFY ]]
DEFAULT_TEST = "test" --[[ MODIFY ]]
-- workspace
workspace(PRJ_NAME)
   -- build options
   configurations { "debug", "release", "dist" }
   -- startproject
   startproject(DEFAULT_TEST)
   -- console
   kind "ConsoleApp"
   -- cpp
   language "C++"
   cppdialect "C++Latest"
   -- includedirs
   includedirs {
      ROOT,
      ROOT .. "/src",
      ROOT .. "/vendor/*/include",
   }
   -- bin
   -- bin :: targetdir
   targetdir(ROOT .. "/bin/%{cfg.buildcfg}/%{prj.name}")
   -- bin :: objdir
   objdir(ROOT .. "/bin/obj/%{cfg.system}_%{cfg.buildcfg}/%{prj.name}")
   -- debug
   debugger "GDB"
   -- config
   -- config :: debug
   filter "configurations:debug"
      -- symbols
      symbols "On"
      -- define
      defines { "CONFIG_DEBUG" }
   -- config :: fast
   filter "configurations:release"
      -- optimize
      optimize "On"
      -- define
      defines { "CONFIG_RELEASE" }
      -- linkoptions
      linkoptions{ "-Ofast" }
   -- config :: dist
   filter "configurations:dist"
      -- optimize
      optimize "On"
      -- define
      defines { "CONFIG_DIST" }
      -- linkoptions
      linkoptions { "-Ofast" }
-- project
-- project :: lib
project(PRJ_NAME)
   -- staticlib
   kind "StaticLib"
   -- files
   files {
      ROOT .. "/src/**",
   }
   -- obj
   objdir(ROOT .. "/bin/obj/%{cfg.system}_%{cfg.buildcfg}")
   -- targetdir
   targetdir(ROOT .. "/lib/%{cfg.buildcfg}")
-- project :: tests
-- project :: tests :: test
project "test"
   -- files
   files {
      ROOT .. "/tests/%{prj.name}.cpp",
      --[[ INSERT ADDITIONAL FILES HERE ]]
   }
   -- link
   links { PRJ_NAME, "glfw", "GLEW", "GL", "GLU", --[[ INSERT ADDITIONAL LINKS HERE ]] }
   -- defines
   defines { --[[ INSERT ADDITIONAL DEFINES HERE ]] }
--[[ INSERT ADDITIONAL TESTS HERE ]]